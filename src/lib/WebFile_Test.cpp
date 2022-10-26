#include "WebFile.hpp"

#include <boost/test/unit_test.hpp>

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
