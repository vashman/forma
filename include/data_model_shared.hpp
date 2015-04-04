// forma context lib

#ifndef FORMA_DATA_MODEL_SHARED_HPP
#define FORMA_DATA_MODEL_SHARED_HPP

#include <istream>
#include "tag.hpp"

namespace forma {
/* get_tag
retrieves the next element as a tag.
*/
template <typename charT, typename traits, typename allocator>
basic_tag<charT,traits,allocator>
get_tag(
  std::basic_istream<charT,traits> &
, charT const /* end of record delimnator */
, charT const /* tag delimantor */
);

} /* forma */
#include "bits/data_model_shared.tcc"
#endif