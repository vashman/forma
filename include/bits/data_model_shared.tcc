//

#ifndef FORMA_DATA_MODEL_SHARED_TCC
#define FORMA_DATA_MODEL_SHARED_TCC

#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <string>
#include <utility>

namespace forma {
/* get_tag
get next tag from database
*/
template <typename charT, typename traits, typename allocator>
basic_tag<charT,traits,allocator>
get_tag(
  std::basic_istream<charT,traits> & _stream
, charT const _record_delim /* end of record delimnator */
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
throw std::runtime_error("Could not determine tag, database stream is not well formatted.");
}

} /* forma */
#endif