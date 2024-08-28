#include "spHistory.hpp"

#include "WebTable.hpp"

spHistory::spHistory():
  history(nullptr),
  SpecialPage("about:history")
{
  setMediaContent("history");
  setName("History");
  setComment("Handle recently visited web sites.");

}

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
  /*
  for (auto c : *history->)
    {
      // Name
      wt.appendItem(c->getName());
      // Link
      auto url = c->getUrl();
      QString urlAsLink = "<a href='" + url + "'>" + url + "</a>";
      wt.appendItem(urlAsLink);

      // Comment
      wt.appendItem(c->getComment());
    }
  */
  
  auto table = wt.toHtml();
  return replaceText("{{SPAGES}}", table);

}
