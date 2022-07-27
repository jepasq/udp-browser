#include "ui/ui_MainWindow.h" // MOC generated file

#include <QWidget>

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
  explicit MainWindow(QWidget *parent = nullptr);
  virtual ~MainWindow();						
						
private slots:
  void on_pbMode_clicked(bool value);
  void on_pbHamburger_clicked(bool value);

protected:
  void    nextMode();
  QString modeToStr();
  
private:
  BrowserMode mode;   //!< The current mode
  Ui::MainWindow ui;  //!< The ui objects from the designer .ui file

  QMenu* hamMenu;      //!< The hamberger menu
};
