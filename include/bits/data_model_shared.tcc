//

#ifndef FORMA_DATA_MODEL_SHARED_TCC
#define FORMA_DATA_MODEL_SHARED_TCC

#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <string>
#include <utility>
#include <limits>

namespace forma {
/* get_tag
  Get the next tag from the database
  stream.
*/
template <
  typename tagT
, typename charT
, typename traits
, typename alloc
>
tagT
get_tag(
  std::basic_istream<
    charT
  , traits
  , alloc
  > & _stream
, delimT const _delim
){
std::basic_string<charT,traits,alloc>
  buff;
  if (
    std::getline(_stream, buff, _delim)
  ){
  return tagT(buff.c_str());
  }
throw std::runtime_error("Could not determine tag, database stream is not well formatted.");
}

/* check_header
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
){
std::size_t count (
 std::numeric_limits<std::size_t>::min()
);
  while (
    (_begin != _end)
  &&
    (count < _length)
  ){
    if ((*_begin) != _header[count]){
    return false;
    }
  ++count;
  ++_begin;
  }
  if (count < _length) return false;
return true;
}

} /* forma */
#endif