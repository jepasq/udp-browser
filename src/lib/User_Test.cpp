#include "User.hpp"

//#define BOOST_TEST_MODULE WebContent
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( user_can_be_instantiated )
{
  User u;
}

// Has a WebContent list and start with a default one
BOOST_AUTO_TEST_CASE( user_has_a_webcontent_list )
{
  User u;
  auto l = u.getWebContentList();
  BOOST_CHECK( l.size() == 1 );
			     
}

