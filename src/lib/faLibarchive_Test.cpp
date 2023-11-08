#include "faLibarchive.hpp"

#include <boost/test/unit_test.hpp>

#include <fstream>

// Call memory access violation suspected code ?
// Setting this to false may make some test fail
bool safe = true;

#define SAFE if (safe)

BOOST_AUTO_TEST_CASE( faLibArchive_can_be_instanciated )
{
  faLibarchive fal;
}

// Has a string/file list
BOOST_AUTO_TEST_CASE( faLibArchive_can_add_file )
{
  faLibarchive fal;
  BOOST_CHECK( fal.getFiles().size() == 0 );

  fal.addFile("aze.txt");
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
  std::cout << size1 << "!=" <<  fal.getFiles().size() << std::endl;
  BOOST_CHECK(fal.getFiles().size() == size1 + 1);
}

/// Actually, file is a simple string, change it to WebFile
BOOST_AUTO_TEST_CASE( faLibArchive_load_file_has_content )
{
  faLibarchive fal;
  auto filen = "aze.out";
  fal.setFilename(filen);
  fal.load();

  SAFE{
    std::cout << "getFiles size : " << fal.getFiles().size() << std::endl;
    auto f1 = fal.getFiles()[0];
    auto c = f1->getContent(); // At least it compiles
  }
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

  SAFE{
    auto f1 = fal.getFiles()[0];
    BOOST_CHECK( !f1->getContent().isEmpty() );
  }
}

BOOST_AUTO_TEST_CASE( faLibArchive_save_file )
{
  faLibarchive fal;

  std::shared_ptr<WebFile> wf = fal.addFile("name");
  BOOST_CHECK( wf ); // Not null
}

BOOST_AUTO_TEST_CASE( faLibArchive_save_file_with_content )
{
  faLibarchive fal;
  fal.setFilename("fatest.out");

  std::shared_ptr<WebFile> wf = fal.addFile("name");
  SAFE{
    wf->setContent("Aaaze");
    fal.write();
  }
  BOOST_CHECK( wf ); // Not null
}

BOOST_AUTO_TEST_CASE( faLibArchive_write_file_empty_filename )
{
  faLibarchive fal;
  fal.setFilename("");
  BOOST_CHECK_THROW(fal.write(), std::runtime_error);
}

BOOST_AUTO_TEST_CASE( faLibArchive_load_file_with_content )
{
  faLibarchive fal;
  fal.setFilename("fatest.out");

  SAFE{
    fal.load();
  }
  auto files = fal.getFiles();
  BOOST_CHECK( files.size() != 0 ); // Not null

  // The next test may fail with a 'memory access violation' error (a segfault)
  // if the file list is empty
  if (files.size() > 0)
    {  
      auto s = files[0]->getContent();
      BOOST_CHECK( s == "Aaaze" ); // Not null
    }
}



