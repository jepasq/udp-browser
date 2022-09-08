#ifndef __USER_HPP__
#define __USER_HPP__

#include <list>

#include "WebContent.hpp"

/** Defined the current user
  *
  * Mainly to provide a way to get multiple WebContent (different websites)
  * per user.
  *
  */
class User
{
public:
  User();
  
  std::list<WebContent*> getWebContentList();

private:

  std::list<WebContent*> webContentList;
  
};

#endif // !__USER_HPP__

