#include "WebContent.hpp"

//#define BOOST_TEST_MODULE WebContent
#include <boost/test/unit_test.hpp>

// Test that save and loads are defined
BOOST_AUTO_TEST_CASE( save_and_load )
{
  WebContent wb;
  wb.save();
  
  wb.load();
}
