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
  BOOST_CHECK( wt.toHtml().contains("<table>"));
  BOOST_CHECK( wt.toHtml().contains("</table>"));
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
  auto html = wt._openTag("aze", "cla55");
  BOOST_CHECK( html.contains("<aze"));
  BOOST_CHECK( html.contains("cla55"));
}

  
BOOST_AUTO_TEST_CASE( WebTable_changeQuote )
{
  WtSubclass wt;
  wt.changeQuoteChar('T');
  BOOST_CHECK( wt._openTag("aze", "cla55") == "<aze class=Tcla55T>");
}

BOOST_AUTO_TEST_CASE( WebTable_items )
{
  WebTable wt;
  wt.setHeaders({ "Name", "Age"});
  wt.setItems({ "AAA", "245", "BBB", "45"});
  BOOST_CHECK( wt.toHtml().contains("AAA"));
}

