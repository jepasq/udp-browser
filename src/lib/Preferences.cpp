#include "Preferences.hpp"

#include <QFile>
#include <QDataStream>

Preferences::Preferences(const QString& filen):
  Serializer(filen),
  quotaNum(500)
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
  ds << quotaNum;
  ds << quotaUnit;
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
  ds >> quotaNum;
  ds >> quotaUnit;
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
Preferences::setQuota(unsigned int num, QuotaUnit_t unit)
{
  quotaNum  = num;
  quotaUnit = unit;
}

unsigned int
Preferences::getQuotaNum(void) const
{
  return quotaNum;
}

QuotaUnit_t
Preferences::getQuotaUnit(void) const
{
  return quotaUnit;
}
