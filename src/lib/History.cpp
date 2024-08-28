#include "History.hpp"

void History::add(const std::string& url, const std::string& title)
{
  items.push_front(std::make_shared<HistoryItem>(url, title));
}

std::list<std::shared_ptr<HistoryItem>>
History::getItems(void) const
{
  return items;
}
