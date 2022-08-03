#ifndef __PREFERENCES_HPP__
#define __PREFERENCES_HPP__

#include <QString>

#include "Serializer.hpp"

/** Handles localc preferences of the user, to be serialized and load at runtime
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
  
private:
  QString      username; //!< The local username
  unsigned int quota;    //!< Quota in Kb
};

#endif // !__PREFERENCES_HPP__
