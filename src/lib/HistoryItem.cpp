#include "HistoryItem.hpp"

/** Default constructor
 *
 *  @param vUrl   The URL.
 *  @param vTitle The Title.
 *
 *
 */
HistoryItem::HistoryItem(const std::string& vUrl, const std::string& vTitle):
  url(vUrl),
  title(vTitle)
{

}

/** Change this item's URL
 *
 *  @param u The new URL.
 *
 */
void
HistoryItem::setUrl(const std::string& u)
{
  url = u;
}

/** Return this item's URL
 *
 *  @return The current URL.
 *
 */
const std::string&
HistoryItem::getUrl(void) const
{
  return url;
}


/** Change this item's title
 *
 *  @param t The new title.
 *
 */
void
HistoryItem::setTitle(const std::string& t)
{
  title = t;
}

/** Return this item's title
 *
 *  @return The current title.
 *
 */
const std::string&
HistoryItem::getTitle(void) const
{
  return title;
}

