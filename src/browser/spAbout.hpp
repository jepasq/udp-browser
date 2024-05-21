#ifndef __SPECIAL_PAGE_ABOUT_HPP__
#define __SPECIAL_PAGE_ABOUT_HPP__

#include "SpecialPage.hpp"

#include <QList>

/** The about:about special page, listing all other special pages
  *
  */
class spAbout : public SpecialPage
{
public:
  spAbout();

  void setData(QList<SpecialPage*>*);
  virtual QString process() override;
  
private:
  QList<SpecialPage*>* pages;
};

#endif // !__SPECIAL_PAGE_ABOUT_HPP__
