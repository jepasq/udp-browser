#include "WebFile.hpp"

#include <boost/test/unit_test.hpp>

#include <stdexcept> // USES std::runtime_error

BOOST_AUTO_TEST_CASE( WebFile_can_be_instanciated )
{
  WebFile wf;
  //  BOOST_CHECK( wf != nullptr );
}

BOOST_AUTO_TEST_CASE( WebFile_get_content )
{
  WebFile wf;
  BOOST_CHECK( wf.getContent().isEmpty());
}

BOOST_AUTO_TEST_CASE( WebFile_set_content )
{
  WebFile wf;
  auto ct = wf.getContent();
  QString new_content = "AZEazeazeAZE";

  wf.setContent(new_content);
  
  BOOST_CHECK( wf.getContent() != ct);
}

/// Must have a getFilename function but shouldn't be empty
BOOST_AUTO_TEST_CASE( WebFile_get_filename )
{
  WebFile wf;
  BOOST_CHECK( !wf.getFilename().isEmpty() );
}

BOOST_AUTO_TEST_CASE( WebFile_set_filename )
{
  WebFile wf;
  auto ct = wf.getFilename();
  QString new_filename = "AZEazeazeAZE";

  wf.setFilename(new_filename);
  BOOST_CHECK( wf.getFilename() != ct);
}

/// Should throw an exception if we try to set an empty filename
BOOST_AUTO_TEST_CASE( WebFile_set_empty_filename )
{
  WebFile wf;
  BOOST_CHECK_THROW(wf.setFilename(""), std::runtime_error);
}

/// Should throw an exception if we try to save a file with empty filename
BOOST_AUTO_TEST_CASE( WebFile_save_with_empty_filename )
{
  WebFile wf;
  QDataStream ds;  
  // Shouldn't raise an error as WebFile has a default non-empty filename
  wf.save(ds)     ;

  WebFile wf2("");
  BOOST_CHECK_THROW(wf2.save(ds), std::runtime_error);
}

