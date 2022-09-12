#include "MainWindow.hpp"

#include <iostream>

#include "config.h" // USES WTITLE
#include "PreferencesDialog.hpp"
#include "Preferences.hpp"
#include "User.hpp"
/** The main window constructor
  *
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
  hamMenu = new QMenu("Global menu", this);
  hamMenu->addAction(prefAction);

  ui.pbHamburger->setMenu(hamMenu);
  connect(prefAction, &QAction::triggered,
	  this, &MainWindow::onPreferencesClicked);

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

void
MainWindow::on_pbMode_clicked(bool value)
{
  nextMode();
  ui.stackedWidget->setCurrentIndex(static_cast<int>(mode));
  ui.pbMode->setText(modeToStr());
}

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

void
MainWindow::onPreferencesClicked(bool value)
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
