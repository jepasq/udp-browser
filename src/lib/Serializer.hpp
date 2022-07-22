#ifndef __SERIALIZER_HPP__
#define __SERIALIZER_HPP__

#include <QString>

class Serializer
{
public:
  Serializer(const QString&);

  void load(/* ProjectFile* or WebContent */);
  void save(/* ProjectFile* */);

  const QString& getFilename(void) const;
  void           setFilename(const QString&);
  
private:
  QString filename;  //!< The target path
};

#endif // !__SERIALIZER_HPP__

