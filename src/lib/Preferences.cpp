#include "Preferences.hpp"

Preferences::Preferences():
  Serializer("preferences.dat")
{

}

void
Preferences::save(void)
{
  Serializer::save();
}

void
Preferences::load(void)
{
  Serializer::load();

}
