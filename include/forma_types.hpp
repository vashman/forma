// basic types shared by plugins and main

//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef FORMA_FORMA_TYPES_HPP
#define FORMA_FORMA_TYPES_HPP

#include <string>
#include "tag.hpp"
#include "flag.hpp"

namespace forma {

typedef char char_t;
typedef std::char_traits<char_t> traits_t;
typedef basic_tag<char_t, traits_t, std::allocator<char_t> > tag_t;
typedef basic_flag<char_t, traits_t, std::allocator<char_t> > flag_t;

} /* forma */

#endif
