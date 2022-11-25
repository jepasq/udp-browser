#include "MainWindow.hpp"

#include <iostream>

#include "config.h" // USES WTITLE
#include "PreferencesDialog.hpp"
#include "Preferences.hpp"
#include "User.hpp"
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
  std::cout << "Show Help dialog..." << std::endl;

}

/** The Help button slot
 *
 * \param value Show an About dialog.
 *
 */
void
MainWindow::onAboutClicked(bool value)
{
  std::cout << "Show About dialog..." << std::endl;

}
