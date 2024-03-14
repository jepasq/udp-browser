#include "MainWindow.hpp"

#include <iostream>

#include <QMessageBox> // USES QMessageBox::about()
#include <QMimeData>
#include <QProcess>
#include <QEvent>
#include <QMouseEvent>
#include <QDrag>

#include "config.h" // USES WTITLE
#include "PreferencesDialog.hpp"
#include "Preferences.hpp"
#include "SpecialPage.hpp"
#include "User.hpp"

// Should work on some compilers (from #if __has_include("myinclude.h"))
#if __has_include(<boost/version.hpp>)
#  include <boost/version.hpp> // USES BOOST_VERSION
#endif

#if __has_include(<boost/config.hpp>)
#  include <boost/config.hpp>  // USES BOOST_COMPILER
#endif

//#include <boost/config/suffix.hpp>  // On newer versions

// See https://stackoverflow.com/a/1505631
// Check windows
#if _WIN32 || _WIN64
#if _WIN64
#define ENVB 64
#else
#define ENVB 32
#endif
#endif

// Check GCC
#if __GNUC__
#if __x86_64__ || __ppc64__
#define ENVB 64
#else
#define ENVB 32
#endif
#endif

/** The main window constructor
  *
  * \param p      The user preferences object (includes username, quota etc...).
  * \param parent An optional parent defaulted to nullptr.
  *
  */
MainWindow::MainWindow(Preferences* p, QWidget* parent):
  mode(BM_BROWSER),
  hamMenu(nullptr),
  pref(p),
  user(nullptr)
{
  ui.setupUi(this);

  // Set initial button's label and stackedWidget's page
  ui.stackedWidget->setCurrentIndex(static_cast<int>(mode));
  ui.pbMode->setText(modeToStr());

  setTitle();
  
  auto prefAction = new QAction("&Preferences", this);
  auto helpAction = new QAction("&Help", this);
  auto aboutAction = new QAction("&About", this);
  auto quitAction = new QAction("&Quit", this);
  hamMenu = new QMenu("Global menu", this);
  hamMenu->addAction(prefAction);
  hamMenu->addSeparator();
  hamMenu->addAction(helpAction);
  hamMenu->addAction(aboutAction);
  hamMenu->addSeparator();
  hamMenu->addAction(quitAction);
  
  ui.pbHamburger->setMenu(hamMenu);
  connect(prefAction, &QAction::triggered, this, &MainWindow::onPrefClicked);
  connect(helpAction, &QAction::triggered, this, &MainWindow::onHelpClicked);
  connect(aboutAction, &QAction::triggered,this, &MainWindow::onAboutClicked);
  connect(quitAction, &QAction::triggered,this, &MainWindow::onQuitClicked);

  // Trying to handle drag event
  connect(ui.tbPar, &QToolButton::triggered, this, &MainWindow::onParClicked);

  connect(ui.pbGo, &QToolButton::clicked, this, &MainWindow::onGoClicked);
  connect(ui.leUrl, &QLineEdit::returnPressed, this, &MainWindow::onGoClicked);
  
  connect(ui.pbSearch,&QToolButton::clicked,this,&MainWindow::onSearchClicked);

  user = new User();

  // Create Special Pages and populate list
  auto spHome = new SpecialPage("about:home");
  spHome->setMediaContent("home");
  spages.push_back(spHome);

  ui.webEngineView->setUrl(spHome->getContent());
  
  auto spAbout = new SpecialPage("about:about");
  spAbout->setMediaContent("about");
  // setContentUrl here!!!
  spages.push_back(spAbout);
}

/** The window destructor
  *
  */
MainWindow::~MainWindow()
{
  delete hamMenu;
  delete user;
}

/** The browser mode button callback
 *
 * \param value Unsused parameter.
 *
 */ 
void
MainWindow::on_pbMode_clicked(bool value)
{
  nextMode();
  ui.stackedWidget->setCurrentIndex(static_cast<int>(mode));
  ui.pbMode->setText(modeToStr());
}

/** Change browser to next mode
 *
 */
void
MainWindow::nextMode()
{
  // This is the total number of mode to cycle through
  constexpr int modeNumber = 2;
  mode = static_cast<BrowserMode>((mode + 1)%modeNumber);
}

/** Returns a QString representing the current mode
  *
  * \return As a QString. To get a std::string, try .toStdString().
  *
  */
QString
MainWindow::modeToStr()
{
  QString m[] = {"Browser", "Editor"};
  int i = static_cast<int>(mode);
  return m[i];
}

/** The Preferences button slot
 *
 * Must show the preferences handling dialog.
 *
 */
void
MainWindow::onPrefClicked(bool value)
{
  std::cout << "Show preferences dialog..." << std::endl;
  PreferencesDialog prd;
  prd.load(pref);
  prd.exec();
  prd.save(pref);
  pref->save();

  setTitle();
}

/** Set the window title according to the username
  *
  */
void
MainWindow::setTitle()
{
  QString u=pref->getUsername();
  if (u.isEmpty())
    setWindowTitle(WTITLE);
  else
    setWindowTitle(u+"@"+WTITLE);
}

/** The Help button slot
 *
 * \param value An unused boolean.
 *
 */
void
MainWindow::onHelpClicked(bool value)
{
  std::cout << "Launching Qt Assistant..." << std::endl;

  QProcess *process = new QProcess;
  QStringList args;
  args << QLatin1String("-collectionFile")
       << QLatin1String("udp-browser.qhc")
       << QLatin1String("-enableRemoteControl");
  process->start(QLatin1String("assistant"), args);
  if (!process->waitForStarted())
    return;
  
}

/** The Help button slot
 *
 * \param value Show an About dialog.
 *
 */
void
MainWindow::onAboutClicked(bool value)
{
  QString title = "About ";
  title += PROJECT_NAME;
  QString txt = WTITLE;

  txt += " (" + QString::number(ENVB) + " bits)";
  txt += "\nBuild on " + QString(__DATE__) + " at " + QString(__TIME__);

#ifdef BOOST_LIB_VERSION 
  txt += "\nUsing Boost " + QString(BOOST_LIB_VERSION);
#endif  

#ifdef BOOST_COMPILER
  txt += "\nbuild with " + QString(BOOST_COMPILER);
#endif  
  QMessageBox::about(this, title, txt);
}

/** The paragraph toolbar button clicked slot
  *
  * \param value The button is uncheckable. Should always be false. See
  *              https://doc.qt.io/qt-6/qaction.html#triggered .
  *
  */
void
MainWindow::onParClicked(bool value)
{
  /*
  if (event->button() == Qt::LeftButton)
    dragStartPosition = event->pos();
  */
  std::cout << "Par toolbutton clicked" << std::endl;
}


/** The mouse move event
  *
  * Mainly used to handle drag and drop feature. Using dragStartPosition
  * as main member.
  *
  * \param e The event pointer.
  *
  */
void
MainWindow::mouseMoveEvent(QMouseEvent *e)
{
  if (!(e->buttons() & Qt::LeftButton))
    return;
  if ((e->pos() - dragStartPosition).manhattanLength()
      < QApplication::startDragDistance())
    return;

  std::cout << "Mouse move" << e->pos().x() << ":" << e->pos().y() << std::endl;

  
  QDrag *drag = new QDrag(this);
  QMimeData *mimeData = new QMimeData;
  
  //  mimeData->setData(mimeType, data);
  drag->setMimeData(mimeData);
  
  Qt::DropAction dropAction = drag->exec(Qt::CopyAction | Qt::MoveAction);
}

/** The quit menu button slot
 *
 * \param value An unused boolean.
 *
 */
void
MainWindow::onQuitClicked(bool value)
{
  QCoreApplication::quit();
}

/** Get the URL from the UI widget
  *
  * \return The URL as a QString reference.
  *
  */
QString
MainWindow::getUrl() const
{
  return ui.leUrl->text();
}

/** The Go button callback
  *
  */
void
MainWindow::onGoClicked()
{
  auto url = getUrl();
  std::cout << "Go clicked! URL is '" << url.toStdString() << "'" << std::endl;

  for (auto &p : spages)
    {
      // Now comprage searched string with page URL
      if (p->getUrl() == url)
	std::cout << "Going to '" << url.toStdString()
		  << "' special page!!" << std::endl;

      ui.webEngineView->setUrl(p->getContent());
      
    }
  
}

/** Get the search string from the UI widget
  *
  * \return The search terms
  *
  */
QString
MainWindow::getSearch() const
{
  return ui.leSearch->text();
}

/** The Go button callback
  *
  */
void
MainWindow::onSearchClicked()
{
  auto search = getSearch().toStdString();

  
  std::cout << "Search engine not implemented '" << search << "'" << std::endl;
}

