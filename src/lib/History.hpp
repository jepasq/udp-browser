#ifndef _HISTORY_HPP_
#define _HISTORY_HPP_

#include <list>
#include <string>
#include <memory>  // USES shared_ptr

struct HistoryItem
{
  HistoryItem(const std::string& u, const std::string& t):url(u), title(t){}
  std::string url;
  std::string title;
};

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
  
private:
  std::list<std::shared_ptr<HistoryItem>> items;
};

#endif // !_HISTORY_HPP_
