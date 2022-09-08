#include "User.hpp"

User::User()
{
  webContentList.push_back(new WebContent());
}


std::list<WebContent*>
User::getWebContentList()
{
  return webContentList;
}
