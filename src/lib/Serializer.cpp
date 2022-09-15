#include "Serializer.hpp"

#include <QFile>
#include <QDataStream>

/** Constructor with filename
  *
  * \param fname The QFile file name.
  *
  */
Serializer::Serializer(const QString& fname):
  filename(fname)
{
  
}

/** Save content to the curent filename and return file
  *
  * \return The opened file.
  *
  */
QFile&
Serializer::save()
{
  file.setFileName(filename);
  file.open(QIODevice::WriteOnly);
  //  QDataStream out(&file);   // we will serialize the data into the file
  /*  out << QString("the answer is");   // serialize a string
  out << (qint32)42;        // serialize an integer
  */
  return file;
}

/** Load content from the curent filename and return file
  *
  * \return The opened file.
  *
  */
QFile&
Serializer::load()
{
  file.setFileName(filename);
  file.open(QIODevice::ReadOnly);
  //  QDataStream in(&file);
  return file;
}

/** Get the current filename
  *
  * \return The filename member.
  *
  */
const QString&
Serializer::getFilename(void) const
{
  return filename;
}

/** Change the current filename
  *
  * \param fname The new filename.
  *
  */
void
Serializer::setFilename(const QString& fname)
{
  filename = fname;
}

/** Close the underlying file
  *
  */
void
Serializer::close()
{
  file.close();
}
