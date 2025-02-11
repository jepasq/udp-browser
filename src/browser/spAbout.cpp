#include "spAbout.hpp"

#include <iostream>

#include "WebTable.hpp"

/** The About special page constructor
 *
 */
spAbout::spAbout():
  SpecialPage("about:about")
{
  setMediaContent("about");
  setName("About");
  setComment("Contains build versions and special pages table.");

}

/** Change the pages pointer to a new one
  *
  * \param p The new special pages list pointer.
  *
  */
void
spAbout::setData(QList<SpecialPage*>* p)
{
  this->pages = p;
}

/** Process the page before showing it to end user
 *
 *  @return The pas content after about pages WebTable processing.
 *
 */
QString
spAbout::process()
{
  using namespace std;
  
  WebTable wt;
  wt.setHeaders({"Name", "Link", "Comment"});
  for (auto c : *pages)
    {
      // Name
      wt.appendItem(c->getName());
      // Link
      auto url = c->getUrl();
      QString urlAsLink = "<a href='" + url + "'>" + url + "</a>";
      cout << urlAsLink.toStdString() << endl;
      wt.appendItem(urlAsLink);

      // Comment
      wt.appendItem(c->getComment());
    }
  
  auto table = wt.toHtml(); 
  return replaceText("{{SPAGES}}", table);
}
