#include "NetworkNode.hpp"

#include <string>
#include <fstream>
#include <QString>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( netnode_can_be_instanciated )
{
  // Not sure we'll keep this if we have subclasses
  NetworkNode nn;
  //  BOOST_CHECK( 1 == 1 );
}

BOOST_AUTO_TEST_CASE( netnode_download_127001 )
{
  // Not sure we'll keep this if we have subclasses
  NetworkNode nn;
  //  nn.download("127.0.0.1"); // Blocking call
  //  BOOST_CHECK( 1 == 1 );
}

