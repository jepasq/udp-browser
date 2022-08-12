#include <iostream>

#include "MainWindow.hpp"
#include "Preferences.hpp"
#include "ConfigReader.hpp"

#include "config.h"

#include <memory>

int
main(int argc, char *argv[])
{
  using std::cout;
  using std::endl;

  ConfigReader cr;


  cout << "Starting " << PROJECT_NAME << " " << PROJECT_NUMBER << endl;

  Preferences p;
  p.load();
  
  auto un = p.getUsername();
  if (un.isEmpty())
    cout << "WARNING: your username is empty" << endl;
  else
    cout << "Welcome back '" << un.toStdString() << "'!" << endl;
  
  QApplication app(argc, argv);
  MainWindow mw(&p);
  mw.show();
  

  return app.exec();
}
