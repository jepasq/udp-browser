#ifndef __MAIN_WINDOW_HPP__
#define __MAIN_WINDOW_HPP__


#include "ui/ui_MainWindow.h" // MOC generated file

#include <QWidget>

// Forward declarations
class Preferences;
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

  void onPreferencesClicked(bool value);

protected:
  void    nextMode();
  QString modeToStr();
  
private:
  BrowserMode mode;   //!< The current mode
  Ui::MainWindow ui;  //!< The ui objects from the designer .ui file

  QMenu* hamMenu;      //!< The hamberger menu
  Preferences* pref;
};

#endif // !__MAIN_WINDOW_HPP__
