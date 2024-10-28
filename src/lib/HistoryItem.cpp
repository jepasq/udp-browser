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

void
HistoryItem::setUrl(const std::string& u)
{
  url = u;
}

const std::string&
HistoryItem::getUrl(void) const
{
  return url;
}

void
HistoryItem::setTitle(const std::string& t)
{
  title = t;
}

const std::string&
HistoryItem::getTitle(void) const
{
  return title;
}

