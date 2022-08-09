#include "Preferences.hpp"

#include <QFile>
#include <QDataStream>

Preferences::Preferences(const QString& filen):
  Serializer(filen),
  quota(500)
{

}

void
Preferences::save(void)
{
  QFile file(filename);
  file.open(QIODevice::WriteOnly);

  //  QDataStream ds(&Serializer::save());
  QDataStream ds(&file);
  ds << username;
  ds << quota;
}

void
Preferences::load(void)
{
  /*
  QDataStream ds(Serializer::load());
  ds >> username;
  ds >> quota;
  */
  QFile file(filename);
  file.open(QIODevice::ReadOnly);
  QDataStream ds(&file);
  ds >> username;
  ds >> quota;
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
