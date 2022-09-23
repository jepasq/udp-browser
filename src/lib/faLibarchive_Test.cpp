#include "faLibarchive.hpp"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( faLibArchive_can_be_instanciated )
{
  faLibarchive fal;
}

// Has a string/file list
BOOST_AUTO_TEST_CASE( faLibArchive_can_add_file )
{
  faLibarchive fal;
  BOOST_CHECK( fal.getFiles().size() == 0 );

  fal.addFile("aze");
  BOOST_CHECK( fal.getFiles().size() == 1 );
}

/// Has a setOutput function
BOOST_AUTO_TEST_CASE( faLibArchive_can_set_output )
{
  faLibarchive fal;
  auto filen = "aze.out";
  BOOST_CHECK( fal.getOutput().empty() );
  
  fal.setOutput(filen);
  BOOST_CHECK( fal.getOutput() == filen );
}

