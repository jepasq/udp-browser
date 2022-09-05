#include "FileCompressor.hpp"

#include <string>
#include <fstream>
#include <QString>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( filecomp_can_be_instanciated )
{
  // Not sure we'll keep this if we have subclasses
  FileCompressor fc;
  //  BOOST_CHECK( 1 == 1 );
}
