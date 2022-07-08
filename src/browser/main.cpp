#include <iostream>

#include "ConfigReader.hpp"

#include "config.h"

int
main()
{
  using std::cout;
  using std::endl;

  ConfigReader cr;
  
  cout << "Starting " << PROJECT_NAME << " " << PROJECT_NUMBER << endl;

  return 0;
}
