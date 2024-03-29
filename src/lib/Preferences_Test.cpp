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

BOOST_AUTO_TEST_CASE( default_username )
{
  Preferences p(fname);
  auto f = p.getUsername();
  
  BOOST_CHECK( f.isEmpty() );
}

BOOST_AUTO_TEST_CASE( set_username )
{
  QString s = "TestOne";
  Preferences p(fname);
  p.setUsername(s);
  
  BOOST_CHECK( p.getUsername() == s );
}

BOOST_AUTO_TEST_CASE( quota_default )
{
  Preferences p(fname);
  auto q=p.getQuotaNum();
  
  BOOST_CHECK( q == 500 );
}


BOOST_AUTO_TEST_CASE( quota_set )
{
  unsigned int quota=1000;
  Preferences p(fname);
  p.setQuota(quota, QU_KB);
  
  BOOST_CHECK( p.getQuotaNum() == quota );
}

BOOST_AUTO_TEST_CASE( save_username )
{
  QString s = "TestOne";
  Preferences p1(fname);
  p1.setUsername(s);
  p1.save();

  Preferences p2(fname);
  p2.load();
  BOOST_CHECK( p2.getUsername() == s );
}




