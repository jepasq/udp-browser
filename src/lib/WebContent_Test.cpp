#include "WebContent.hpp"

#include "WebFile.hpp"

//#define BOOST_TEST_MODULE WebContent
#include <boost/test/unit_test.hpp>

// Test that save and loads are defined
BOOST_AUTO_TEST_CASE( save_and_load )
{
  WebContent wb;
  wb.save();
  
  wb.load();
}

BOOST_AUTO_TEST_CASE( file_number )
{
  WebContent wb;
  BOOST_CHECK( wb.getFileNumber() == 0 );
}

BOOST_AUTO_TEST_CASE( add_file )
{
  WebContent wb;
  auto fn = wb.getFileNumber();
  wb.addFile(new WebFile());
  BOOST_CHECK( wb.getFileNumber() == ++fn );
}

BOOST_AUTO_TEST_CASE( add_file_should_be_permanent )
{
  WebContent wb;
  auto fn = wb.getFileNumber();
  wb.addFile(new WebFile());
  wb.save();


  WebContent wb2;
  BOOST_CHECK( wb2.getFileNumber() == 0 );
  wb2.load();
  BOOST_CHECK( wb2.getFileNumber() == 1 );
}

BOOST_AUTO_TEST_CASE( WebContent_ctor_has_a_name )
{
  WebContent wb("filename", "name");
  BOOST_CHECK( wb.getName() == "name" );
}

BOOST_AUTO_TEST_CASE( WebContent_ctor_literally_has_a_default_name )
{
  WebContent wb;
  BOOST_CHECK( wb.getName() == "default" );
}

BOOST_AUTO_TEST_CASE( WebContent_has_a_setter_and_a_getter )
{
  WebContent wb("filename", "name");
  wb.setName("name22" );
  BOOST_CHECK( wb.getName() == "name22" );
}

BOOST_AUTO_TEST_CASE( WebContent_name_is_permanent )
{
  WebContent wb;
  wb.setName("name22" );
  wb.save();


  WebContent wb2;
  BOOST_CHECK( wb2.getName() == "default" );
  wb2.load();
  BOOST_CHECK( wb2.getName() == "name22" );
}
