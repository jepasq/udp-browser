#include "spHistory.hpp"

#include "History.hpp"
#include "WebTable.hpp"

spHistory::spHistory():
  history(nullptr),
  SpecialPage("about:history")
{
  setMediaContent("history");
  setName("History");
  setComment("Handle recently visited web sites.");

}

/** Set the actual data to a new pointer
 *
 *  @param h The new history object. Will completely replace existing one.
 *
 */
void
spHistory::setData(History* h)
{
  history = h;
}

QString
spHistory::process()
{
  if (!history)
    return ""; // Empty table ?

  WebTable wt;
  wt.setHeaders({"Link", "Title"});

  for (auto c : history->getItems())
    {
      /*      wt.appendItem(QString(c->url.c_str()));
      wt.appendItem(QString(c->title.c_str()));
      */
      wt.appendItem(c->getUrl());
      wt.appendItem(c->getTitle());
      
    }
  auto table = wt.toHtml();
  return replaceText("{{HPAGES}}", table);

}
