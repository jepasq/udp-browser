#ifndef __SPECIAL_PAGE_ABOUT_HPP__
#define __SPECIAL_PAGE_ABOUT_HPP__

#include "SpecialPage.hpp"

#include <QList>

/** The about:about special page, listing all other special pages
 *
 *  The about page is a special page that list all other registered special
 *  pages.
 *
 */
class spAbout : public SpecialPage
{
public:
  spAbout();

  void setData(QList<SpecialPage*>*);
  virtual QString process() override;
  
private:
  QList<SpecialPage*>* pages;   //!< The internal list of special pages
};

#endif // !__SPECIAL_PAGE_ABOUT_HPP__
