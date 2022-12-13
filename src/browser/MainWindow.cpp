#include "MainWindow.hpp"

#include <iostream>

#include <QMessageBox> // USES QMessageBox::about()

#include <QProcess>

#include "config.h" // USES WTITLE
#include "PreferencesDialog.hpp"
#include "Preferences.hpp"
#include "User.hpp"

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
  hamMenu = new QMenu("Global menu", this);
  hamMenu->addAction(prefAction);
  hamMenu->addSeparator();
  hamMenu->addAction(helpAction);
  hamMenu->addAction(aboutAction);

  
  ui.pbHamburger->setMenu(hamMenu);
  connect(prefAction, &QAction::triggered, this, &MainWindow::onPrefClicked);
  connect(helpAction, &QAction::triggered, this, &MainWindow::onHelpClicked);
  connect(aboutAction, &QAction::triggered,this, &MainWindow::onAboutClicked);

  user = new User();
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
  args //<< QLatin1String("-collectionFile")
       //<< QLatin1String("mycollection.qhc")
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

#if defined(__clang__)
  txt+="\nwith CLANG v" + QString::number(__clang_major__) + "."
    + QString::number(__clang_minor__)  + "."
    + QString::number(__clang_patchlevel__);
#elif defined(__GNUC__) || defined(__GNUG__)
  txt += "\nwith GCC v" + QString::number(__GNUC__) + "."
    + QString::number(__GNUC_MINOR__ ) + ".";
    txt += QString::number(__GNUC_PATCHLEVEL__);

#elif defined(_MSC_VER)
  txt+= "\nwith MSVC";
#endif
  
  QMessageBox::about(this, title, txt);
}
