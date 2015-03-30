// forma context lib

#ifndef FORMA_CONTEXT_HPP
#define FORMA_CONTEXT_HPP

#include <istream>
#include <string>
#include <utility>
#include "tag.hpp"

namespace forma {
/* context file header */
template <typename charT>
struct basic_context_header {
  charT comment_delim = '#';
  charT seperator_delim = ':';
  charT section_delim = '\n';
};

/* get database header and verify */
template <typename charT, typename traits>
basic_context_header<charT>
get_context_header(
  std::basic_istream<charT,traits> &
);

template <typename charT, typename traits, typename allocator>
basic_tag<charT,traits,allocator>
get_tag(
  std::basic_istream<charT,traits> &
, charT /* end of record delimnator */
, charT /* tag delimantor */
);

template <typename charT, typename traits, typename allocator>
std::pair<basic_tag<charT,traits,allocator>
  , std::basic_string<charT,traits,allocator> >
get_tag_value(
  std::basic_string<charT,traits,allocator>
, charT
, charT
);

} /* forma */

#include "./bits/forma_context.tcc"
#endif
