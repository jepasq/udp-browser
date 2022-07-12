#include "ui/ui_MainWindow.h" // MOC generated file

#include <QWidget>

/** The actual browser mode
  *
  */
enum BrowserMode
  {
    BM_BROWSER,  //!< We're in browser mode
    BM_EDITOR    //!< We're editing our webspace
  };

/** The main browser window
  *
  */
class MainWindow : public QMainWindow
{
 Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);

private:
  BrowserMode mode;
  Ui::MainWindow ui;
};
