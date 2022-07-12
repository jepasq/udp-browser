#include <iostream>

#include "ConfigReader.hpp"

#include "config.h"

//#include "ui_MainWindow.h" # MOC generated file

static QWidget*
loadUiFile(QWidget *parent)
{
  QFile file(":/forms/textfinder.ui");
  file.open(QIODevice::ReadOnly);
  
  QUiLoader loader;
  return loader.load(&file, parent);
}

int
main()
{
  using std::cout;
  using std::endl;

  ConfigReader cr;


  QApplication app(argc, argv);
  QWidget widget;
  /*  Ui::MainWindow ui;
  ui.setupUi(&widget);
  */
  loadUiFile(&widget);
  widget.show();
  
  cout << "Starting " << PROJECT_NAME << " " << PROJECT_NUMBER << endl;

  return 0;
}
