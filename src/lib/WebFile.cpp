#include "WebFile.hpp"

/** Webfile constructor
  *
  */
WebFile::WebFile():
  content("")
{

}

/** Load the content of this file from a stream
  *
  * \param ds The stream.
  *
  */
void
WebFile::load(QDataStream& ds)
{

}

/** Load the content of this file from a stream
  *
  * \param ds The stream.
  *
  */
void
WebFile::save(QDataStream& ds)
{

}

/** Get the content of the file
  *
  * May be an empty string.
  *
  */
const QString&
WebFile::getContent(void) const
{
  return content;
}
