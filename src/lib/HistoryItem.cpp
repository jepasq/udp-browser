#include "HistoryItem.hpp"

HistoryItem::HistoryItem(const std::string& u, const std::string& t):
  url(u),
  title(t)
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

