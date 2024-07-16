#include "WebTable.hpp"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( WebTable_nocontent )
{
  WebTable wt;
  BOOST_CHECK( wt.toHtml() == "<table></table>" );
}

BOOST_AUTO_TEST_CASE( WebFile_ )
{
  WebTable wt;
  QStringList headers = { "Name", "Age", "Comment" };
  wt.setHeaders(headers);
  BOOST_CHECK( wt.toHtml().contains("Comment"));
}
