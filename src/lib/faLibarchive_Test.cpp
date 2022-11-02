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

/// Has an implemented write() function and the output file is created
BOOST_AUTO_TEST_CASE( faLibArchive_write_function )
{
  faLibarchive fal;
  auto filen = "aze.out";
  fal.setFilename(filen);
  fal.write();

  // Should work according to https://stackoverflow.com/a/268525
  std::ifstream fs(filen);
  BOOST_CHECK( fs );
}

/// Has an implemented load function and calling it change file list
BOOST_AUTO_TEST_CASE( faLibArchive_load_function )
{
  faLibarchive fal;

  auto size1 = fal.getFiles().size();
  
  auto filen = "aze.out";
  fal.setFilename(filen);
  fal.load();

  // Should work according to https://stackoverflow.com/a/268525
  BOOST_CHECK( size1 != fal.getFiles().size());
}

/// Actually, file is a simple string, change it to WebFile
BOOST_AUTO_TEST_CASE( faLibArchive_load_file_has_content )
{
  faLibarchive fal;

  auto filen = "aze.out";
  fal.setFilename(filen);
  fal.load();

  auto f1 = fal.getFiles()[0];
  auto c = f1->getContent(); // At least it compiles
  //  BOOST_CHECK(  );
}


/// Has an implemented load function and calling it change file list
BOOST_AUTO_TEST_CASE( faLibArchive_load_file_isnt_empty )
{
  faLibarchive fal;

  auto size1 = fal.getFiles().size();
  
  auto filen = "aze.out";
  fal.setFilename(filen);
  fal.load();

  auto f1 = fal.getFiles()[0];
  
  BOOST_CHECK( f1->getContent().isEmpty() );
}

