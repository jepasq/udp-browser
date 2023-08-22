#ifndef __FA_LIBARCHIVE_HPP__
#define __FA_LIBARCHIVE_HPP__

#include "FileArchiver.hpp"

/** A specialized FileArchiver using libarchive under the hood.
  *
  */
class faLibarchive : public FileArchiver
{
public:
  faLibarchive();

  virtual void write(); //!< Write the file
  virtual void load();  //!< Load the file

protected:
  std::string faStatusToStr(int) const;
};


#endif // !__FA_LIBARCHIVE_HPP__

