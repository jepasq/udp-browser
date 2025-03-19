#include "History.hpp"

/** Add a new shared HistoryItem based on given url and title
 *
 * @param url   The page URL.
 * @param title The associated title.
 *
 */
void History::add(const std::string& url, const std::string& title)
{
  items.push_front(std::make_shared<HistoryItem>(url, title));
}

/** Get current list of items
 *
 *  @return A std::list of history items.
 *
 */
std::list<std::shared_ptr<HistoryItem>>
History::getItems(void) const
{
  return items;
}
