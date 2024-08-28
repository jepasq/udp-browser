#include "spHistory.hpp"

spHistory::spHistory():
  history(nullptr)
{

}

void
spHistory::setData(History* h)
{
  history = h;
}

QString
spHistory::process()
{
  if (!history)
    return ""; // Empty table ?
}
