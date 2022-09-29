#include "faLibarchive.hpp"

#include <boost/test/unit_test.hpp>

#include <fstream>

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

/// Has a setFilename function
BOOST_AUTO_TEST_CASE( faLibArchive_can_set_output )
{
  faLibarchive fal;
  auto filen = "aze.out";
  BOOST_CHECK( fal.getFilename().empty() );
  
  fal.setFilename(filen);
  BOOST_CHECK( fal.getFilename() == filen );
}

/// Has an implemented process function and the output file is created
BOOST_AUTO_TEST_CASE( faLibArchive_process_function )
{
  faLibarchive fal;
  auto filen = "aze.out";
  fal.setFilename(filen);
  fal.process();

  // Should work according to https://stackoverflow.com/a/268525
  std::ifstream fs(filen);
  BOOST_CHECK( fs );
}


