#include "Preferences.hpp"

#define BOOST_TEST_MODULE Preferences
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( can_instanciate )
{
  Preferences p;
  
  BOOST_CHECK( 1 == 1 );
}
