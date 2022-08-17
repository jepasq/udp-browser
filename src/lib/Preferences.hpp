#ifndef __PREFERENCES_HPP__
#define __PREFERENCES_HPP__

#include <QString>

#include "Serializer.hpp"

enum QuotaUnit_t {
  QU_KB,
  QU_MB,
  QU_GB
};

/** Handles locale preferences of the user, to be serialized and
  * load at runtime
  *
  */
class Preferences : public Serializer
{
public:
  Preferences(const QString& filen = "preferences.dat");

  virtual void save(void);
  virtual void load(void);

  void           setUsername(const QString&);
  const QString& getUsername(void) const;

  void         setQuota(unsigned int, QuotaUnit_t);
  unsigned int getQuotaNum(void) const;
  QuotaUnit_t  getQuotaUnit(void) const;

private:
  QString      username;  //!< The local username

  unsigned int quotaNum;  //!< The number part of the quota
    QuotaUnit_t quotaUnit; //!< Quota in bytes
};

#endif // !__PREFERENCES_HPP__
