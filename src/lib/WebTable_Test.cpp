#include "WebTable.hpp"

#include <boost/test/unit_test.hpp>

// To make protected functions testable
class WtSubclass : public WebTable
{
public:
  QString _openTag(const QString& tag, const QString& className = ""){
    return openTag(tag, className);
  };
  QString _closeTag(const QString& tag){ return closeTag(tag);} ;
};

BOOST_AUTO_TEST_CASE( WebTable_nocontent )
{
  WebTable wt;
  BOOST_CHECK( wt.toHtml() == "<table></table>" );
}

BOOST_AUTO_TEST_CASE( WebTable_headers )
{
  WebTable wt;
  QStringList headers = { "Name", "Age", "Comment" };
  wt.setHeaders(headers);
  BOOST_CHECK( wt.toHtml().contains("Comment"));
}

BOOST_AUTO_TEST_CASE( WebTable_openTag )
{
  WtSubclass wt;
  BOOST_CHECK( wt._openTag("aze") == "<aze>");
}

BOOST_AUTO_TEST_CASE( WebTable_closeTag )
{
  WtSubclass wt;
  BOOST_CHECK( wt._closeTag("aze") == "</aze>");
}

BOOST_AUTO_TEST_CASE( WebTable_openTag_withClass )
{
  WtSubclass wt;
  BOOST_CHECK( wt._openTag("aze", "cla55").contains("<aze>"));
}

  
BOOST_AUTO_TEST_CASE( WebTable_changeQuote )
{
  WtSubclass wt;
  wt.changeQuoteChar('T');
  BOOST_CHECK( wt._openTag("aze", "cla55") == "<aze class=Tcla55T>");
}
