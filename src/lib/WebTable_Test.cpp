#include "WebTable.hpp"

#include <boost/test/unit_test.hpp>

// To make protected functions testable
class WtSubclass : public WebTable
{
public:
  /** An acessible openTag reimplementation
   *
   *  @param tag       The markup tag name.
   *  @param className An optional CSS class name.
   *
   *  @return The return of the call to the underlying function.
   */
  QString _openTag(const QString& tag, const QString& className = ""){
    return openTag(tag, className);
  };
  /** An acessible closeTag reimplementation
   *
   *  @param tag The markup tag name to be closed.
   *
   *  @return The return of the call to the underlying function.
   */
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

BOOST_AUTO_TEST_CASE( WebTable_items_append )
{
  WebTable wt;
  wt.setHeaders({ "Name", "Age"});
  wt.appendItems({ "AAA", "245", "BBB", "45"});
  wt.appendItem("AZA");
  BOOST_CHECK( wt.toHtml().contains("BBB"));
  BOOST_CHECK( wt.toHtml().contains("AZA"));
}


