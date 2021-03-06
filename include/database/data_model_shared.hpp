// forma context lib

#ifndef FORMA_DATA_MODEL_SHARED_HPP
#define FORMA_DATA_MODEL_SHARED_HPP

#include <istream>
#include <taxo\tag.hpp>

namespace forma {
/* get_tag
  Retrieves the next element as a tag.
*/
template <
  typename tagT
, typename charT
, typename traits
, typename alloc
>
taxo::basic_tag<charT,traits,allocator>
get_tag(
  std::basic_istream<
    charT
  , traits
  , alloc
  > &
, delimT const _delim
);

/* check_header
  charT should be the char type of the input iterator.
*/
template <
  typename charT
, typename inputIt
>
bool
check_header(
  inputIt _begin
, inputIt _end
, charT const * const _header
, std::size_t const _length
);

} /* forma */
#include "bits/data_model_shared.tcc"
#endif