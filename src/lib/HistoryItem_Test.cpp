#include "HistoryItem.hpp"

#include <string>
#include <fstream>
#include <QString>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( default_ctor )
{
  HistoryItem i("aaa", "bbb");
  BOOST_CHECK( i.getUrl() == "aaa" );
  BOOST_CHECK( i.getTitle() == "aaa" );

}

BOOST_AUTO_TEST_CASE( url_getter_setter )
{
  HistoryItem i("aaa", "bbb");
  BOOST_CHECK( i.getUrl() == "aaa" );
  i.setUrl("aa2");
  BOOST_CHECK( i.getUrl() == "aa2" );
}
