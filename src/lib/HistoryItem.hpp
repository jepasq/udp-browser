#ifndef __HISTORY_ITEM_HPP__
#define __HISTORY_ITEM_HPP__

#include <string>

/** An item in the History list
 *
 * Actually contains url and title fields.
 *
 */
class HistoryItem
{
public:
  HistoryItem(const std::string&, const std::string&);

  void               setUrl(const std::string&);
  const std::string& getUrl(void) const;

  const std::string& getTitle(void) const { return title; }

  
  //private:
  std::string url;    //!< The item's history
  std::string title;  //!< The item's title
};

#endif // !__HISTORY_ITEM_HPP__
