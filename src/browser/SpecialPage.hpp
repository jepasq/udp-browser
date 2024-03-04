#ifndef __SPECIAL_PAGE_HPP__
#define __SPECIAL_PAGE_HPP__

#include <QString>

/** A special page the user can access through a given URL
 *
 */
class SpecialPage
{

public:
  SpecialPage(QString u):url(u){ }
  
private:
  QString url;   //!< The URL this page can be accessed with
  
};

#endif // !__SPECIAL_PAGE_HPP__
