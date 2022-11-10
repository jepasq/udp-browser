#include "Preferences.hpp"

#include <QFile>
#include <QDataStream>

/** File named constructor
  *
  * \param filen The filename.
  *
  */
Preferences::Preferences(const QString& filen):
  Serializer(filen),
  quotaNum(500)
{

}

/** Save the current preferences fields to a new data stream
  *
  */
void
Preferences::save(void)
{
  QDataStream ds(&Serializer::save());
  //QDataStream ds(&file);
  ds << username;
  ds << quotaNum;
  ds << quotaUnit;
  Serializer::close();
}

/** Save the current preferences fields from a newly created data stream
  *
  */
void
Preferences::load(void)
{
  QDataStream ds(&Serializer::load());
  ds >> username;
  ds >> quotaNum;
  ds >> quotaUnit;
  Serializer::close();
}

/** Change the current username
  *
  * \param u the new name as a QString.
  *
  */
void
Preferences::setUsername(const QString& u)
{
  username= u;
}

/** Get the current username
  *
  * \return the current name as a QString. May be an empty string.
  *
  */
const QString&
Preferences::getUsername(void) const
{
  return username;
}

/** Set the current quota-related members
  *
  * \param num  the numeric part of the quota.
  * \param unit the unit part of the quota.
  *
  */
void
Preferences::setQuota(unsigned int num, QuotaUnit_t unit)
{
  quotaNum  = num;
  quotaUnit = unit;
}

/** Get the numeric part of the quota
  *
  * \return An unsigned int.
  *
  */
unsigned int
Preferences::getQuotaNum(void) const
{
  return quotaNum;
}

/** Get the unit part of the quota
  *
  * \return The quota unit.
  *
  */
QuotaUnit_t
Preferences::getQuotaUnit(void) const
{
  return quotaUnit;
}
