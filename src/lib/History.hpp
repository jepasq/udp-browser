#ifndef _HISTORY_HPP_
#define _HISTORY_HPP_

#include <list>
#include <string>
#include <memory>  // USES shared_ptr

#include "HistoryItem.hpp"

/** The web history handling class
  *
  * An ordered list of recently visited links with URL and title.
  *
  */
class History
{
public:
  History();

  void add(const std::string& url, const std::string& title);
  std::list<std::shared_ptr<HistoryItem>> getItems(void) const;
  
private:
  /// The interl list of items
  std::list<std::shared_ptr<HistoryItem>> items; 
};

#endif // !_HISTORY_HPP_
