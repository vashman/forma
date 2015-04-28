// forma context lib

#ifndef FORMA_DATA_MODEL_SHARED_HPP
#define FORMA_DATA_MODEL_SHARED_HPP

#include <istream>
#include <taxo\tag.hpp>

namespace forma {
/* get_tag
retrieves the next element as a tag.
*/
template <
  typename charT
, typename traits
, typename allocator
, typename inputIter
>
taxo::basic_tag<charT,traits,allocator>
get_tag(
  inputIter
, inputIter
, charT const /* end of record delimnator */
, charT const /* tag delimantor */
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