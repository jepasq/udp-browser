#include "Preferences.hpp"

Preferences::Preferences(const QString& filen):
  Serializer(filen)
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
