#ifndef __SPECIAL_PAGE_ABOUT_HPP__
#define __SPECIAL_PAGE_ABOUT_HPP__

#include "SpecialPage.hpp"

/** The about:about special page, listing all other special pages
  *
  */
class spAbout : public SpecialPage
{
public:
  spAbout();

private:
  QList<SpecialPage*>* pages;
};

#endif // !__SPECIAL_PAGE_ABOUT_HPP__
