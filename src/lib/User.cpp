#include "User.hpp"

/** Default constructor
  *
  * Add an empty WebContent by default.
  *
  */
User::User()
{
  webContentList.push_back(new WebContent());
}

/** Returns the current content list
  * 
  *\return The webContentList member.
  *
  */
std::list<WebContent*>
User::getWebContentList()
{
  return webContentList;
}
