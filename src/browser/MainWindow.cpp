#include "MainWindow.hpp"

#include <iostream>

MainWindow::MainWindow(QWidget* parent):
  mode(BM_BROWSER)
{
  ui.setupUi(this);
}

void
MainWindow::on_pbMode_clicked(bool value)
{
  nextMode();
  ui.pbMode->setText(modeToStr());
}

void
MainWindow::nextMode()
{
  // This is the total number of mode to cycle through
  constexpr int modeNumber = 2;
  mode = static_cast<BrowserMode>((mode + 1)%modeNumber);
}

QString
MainWindow::modeToStr()
{
  QString m[] = {"Browser", "Editor"};
  int i = static_cast<int>(mode);
  return m[i];
}
