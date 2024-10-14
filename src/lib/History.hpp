#ifndef _HISTORY_HPP_
#define _HISTORY_HPP_

#include <list>
#include <string>
#include <memory>  // USES shared_ptr

#include "HistoryItem.hpp"

/** The web history handling class
  *
  *
  *
  */
class History
{
public:
  History();

  void add(const std::string& url, const std::string& title);
  std::list<std::shared_ptr<HistoryItem>> getItems(void) const;
  
private:
  std::list<std::shared_ptr<HistoryItem>> items;
};

#endif // !_HISTORY_HPP_
