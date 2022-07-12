#include <iostream>

#include "ConfigReader.hpp"

#include "config.h"

#include "MainWindow.hpp"

int
main(int argc, char *argv[])
{
  using std::cout;
  using std::endl;

  ConfigReader cr;


  cout << "Starting " << PROJECT_NAME << " " << PROJECT_NUMBER << endl;
  QApplication app(argc, argv);
  MainWindow mw;
  mw.show();
  

  return app.exec();
}
