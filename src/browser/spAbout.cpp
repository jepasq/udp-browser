#include "spAbout.hpp"

#include <iostream>

spAbout::spAbout():
  SpecialPage("about:about")
{
  setMediaContent("about");

}

/** Change the pages pointer to a new one
  *
  * \param p The new special pages list pointer.
  *
  */
void
spAbout::setData(QList<SpecialPage*>* p)
{
  this->pages = p;
}

/** Process the page before showing it to end user
  *
  *
  */
void
spAbout::process()
{
  using namespace std;
  
  for (auto c : *pages)
    {
      cout << c << ",";
    }
}
