#ifndef __SPECIAL_PAGE_HISTORY_HPP__
#define __SPECIAL_PAGE_HISTORY_HPP__

#include "SpecialPage.hpp"

// Forward declarations
class History;
// End of Forward declarations

/** The history page
  *
  * Shows a table of visited web adress. We need complete History object
  * to be able to remove itemxs.
  *
  */
class spHistory : public SpecialPage
{
public:
  spHistory();

  void setData(History*);
  virtual QString process() override;

private:
  History* history;
};

#endif // !__SPECIAL_PAGE_HISTORY_HPP__
