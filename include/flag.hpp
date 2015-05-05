// flag = tag + value for the tag

#ifndef FORMA_FLAG_HPP
#define FORMA_FLAG_HPP

#include <string>
#include "tag.hpp"

namespace forma {
/**/
template <typename allocator>
using basic_flag
  = taxo::realtionship <
      taxo::catagory<allocator>
    , allocator
  >;

} /* forma */
#endif
