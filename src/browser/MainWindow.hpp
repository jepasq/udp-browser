#ifndef __MAIN_WINDOW_HPP__
#define __MAIN_WINDOW_HPP__


#include "ui/ui_MainWindow.h" // MOC generated file

#include <QWidget>

// Forward declarations
class Preferences;
class User;
// End of forward declarations


/** The actual MainWindow's  browser mode
  *
  */
enum BrowserMode
  {
    BM_BROWSER = 0,  //!< We're in browser mode
    BM_EDITOR        //!< We're editing our webspace
  };

/** The main browser window
  *
  */
class MainWindow : public QMainWindow
{
 Q_OBJECT

public:
  explicit MainWindow(Preferences*, QWidget *parent = nullptr);
  virtual ~MainWindow();						
						
private slots:
  void on_pbMode_clicked(bool value);

  void onPrefClicked(bool value);
  void onHelpClicked(bool value);
  void onAboutClicked(bool value);

protected:
  void    nextMode();
  QString modeToStr();

  void setTitle();
  
private:
  BrowserMode mode;   //!< The current mode
  Ui::MainWindow ui;  //!< The ui objects from the designer .ui file

  QMenu* hamMenu;      //!< The hamberger menu
  User* user;          //!< The current user
  Preferences* pref;   //!< The current user's preferences
};

#endif // !__MAIN_WINDOW_HPP__
