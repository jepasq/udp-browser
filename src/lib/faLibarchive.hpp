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
};


#endif // !__FA_LIBARCHIVE_HPP__

