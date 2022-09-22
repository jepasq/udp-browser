#include "faLibarchive.hpp"

//#define BOOST_TEST_MODULE WebContent
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( faLibArchive_can_be_instanciated )
{
  faLibarchive fal;
}

// Has a WebContent list and start with a default one
BOOST_AUTO_TEST_CASE( faLibArchive_can_add_file )
{
  faLibarchive fal;
  BOOST_CHECK( fal.getFiles().size() == 0 );

  fal.addFile("aze");
  BOOST_CHECK( fal.getFiles().size() == 1 );
}

