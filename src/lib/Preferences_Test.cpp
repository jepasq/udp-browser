#include "Preferences.hpp"

#include <string>
#include <fstream>
#include <QString>

#define BOOST_TEST_MODULE Preferences
#include <boost/test/unit_test.hpp>

const QString fname = "preferences-test.dat";

bool
file_exists(const std::string& file)
{
  std::ifstream infile(file);
  return infile.good();
}

BOOST_AUTO_TEST_CASE( can_be_instanciated )
{
  Preferences p(fname);
  BOOST_CHECK( 1 == 1 );
}

BOOST_AUTO_TEST_CASE( save_create_file )
{
  Preferences p(fname);
  p.save();
  
  BOOST_CHECK( file_exists(fname.toStdString()));
}

BOOST_AUTO_TEST_CASE( default_filename )
{
  Preferences p(fname);
  auto f = p.getUsername();
  
  BOOST_CHECK( f.isEmpty() );
}


