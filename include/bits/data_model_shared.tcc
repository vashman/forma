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
  Get the next tag from the database stream
*/
template <
  typename charT
, typename traits
, typename allocator
, typename inputIter
>
basic_tag<
  charT
, traits
, allocator
>
get_tag(
  inputIter _first
, inputIter _last
, charT const _tag_delim
){
std::basic_string<charT,traits,allocator> buffer;
  if (std::getline(_stream, buffer, _record_delim)){
  auto itb = std::begin(buffer), ite = std::end(buffer);
  return basic_tag<charT,traits,allocator>(
           itb
         , std::find(itb, ite, _tag_delim)
         , ite);
  }
std::copy(_first,_last,);
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
std::size_t count;
  for (
    count = std::numeric_limits<std::size_t>::min()
  ; (_begin != _end) && (count < _length)
  ; ++count, ++_begin
  ){
    if ((*_begin) != _header[count]){
    return false;    
    }
  }
  if (count < _length) return false;
return true;
}

} /* forma */
#endif