// flag = tag + value for the tag

#ifndef FORMA_FLAG_HPP
#define FORMA_FLAG_HPP

#include <string>
#include "tag.hpp"

namespace forma {
/**/
template <typename charT, typename traits, typename allocator>
using basic_flag
  = taxo::realtionship <
      taxo::catagory<charT,traits,allocator>
    , charT
    , traits
    , allocator
  >;

} /* forma */
#endif
