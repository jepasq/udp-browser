#include "Preferences.hpp"

Preferences::Preferences(const QString& filen):
  Serializer(filen),
  quota(500)
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

void
Preferences::setUsername(const QString& u)
{
  username= u;
}

const QString&
Preferences::getUsername(void) const
{
  return username;
}

void
Preferences::setQuota(unsigned int q)
{
  quota = q;
}

unsigned int
Preferences::getQuota(void) const
{
  return quota;
}
