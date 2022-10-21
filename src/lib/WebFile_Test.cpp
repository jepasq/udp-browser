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
  BOOST_CHECK( wf.getContent().empty());
}

