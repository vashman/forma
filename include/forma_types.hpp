/* Basic types shared by plug-ins and
  the main application.
*/

//          Copyright Sundeep S. Sangha 2013 - 2015.

#ifndef FORMA_FORMA_TYPES_HPP
#define FORMA_FORMA_TYPES_HPP

#include <string>
#include <taxo/tag.hpp>
#include <taxo/realtion.hpp>

namespace forma {

typedef char char_t;

typedef std::char_traits<char_t>
  traits_t;

typedef std::allocator<char>
char_alloc_t;

typedef taxo::tag tag_t;

typedef taxo::relation <
  std::basic_string<
    char_t
  , traits_t
  , char_alloc_t
  >
, char_alloc_t
> flag_t;

} /* forma */

#endif
