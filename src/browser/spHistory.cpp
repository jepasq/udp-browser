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
      wt.appendItem(QString(c->url.c_str()));
      wt.appendItem(QString(c->title.c_str()));
    }
  auto table = wt.toHtml();
  return replaceText("{{HPAGES}}", table);

}
