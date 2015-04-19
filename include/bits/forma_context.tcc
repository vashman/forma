//

#ifndef FORMA_CONTEXT_TCC
#define FORMA_CONTEXT_TCC

#include <algorithm>
#include <iterator>
#include <stdexcept>

namespace forma {
/* get database header and verify */
template <
  typename charT
, typename traits
>
basic_context_header<charT>
get_context_header(
  std::basic_istream<charT,traits>
    & _istream
){
charT const * const header_string
  = "forma context:";
std::streamsize const header_size = 22;
charT buffer[header_size];

_istream.getline(
  buffer
, header_size
, '\n'
);
  if (0
     !=
     traits::compare(
       buffer
     , header_string
     , traits::length(header_string)
     )){
  throw std::runtime_error(
          "header does not compare"
        );
  }
basic_context_header<charT> header;
  switch (traits::length(buffer)){
  case 20:
  header.section_delim = buffer[14 + 5];
  case 18:
  header.seperator_delim = buffer[14 + 3];
  case 16:
  header.comment_delim = buffer[14 + 1];
  break;
  default:
  std::cerr << traits::length(buffer);
  throw std::runtime_error(
          "Header not parsable due to"
          " size difference."
        );
  }

  /* if newline is delim character */
  if (_istream.peek()
     ==
     traits::to_int_type('\n')
     ){
  _istream.get();
  header.section_delim = '\n';
  }
return header;
}

/* get next flag from database */
template <
  typename charT
, typename traits
, typename allocator
>
basic_flag<charT,traits,allocator>
get_tag_value(
  std::basic_istream<charT,traits>
    & _istream
, charT _record_delim
, charT _tag_delim
){
std::basic_string<
  charT
, traits
, allocator
> buffer;
/* A record in a stream will look like:
 tag:root:value\n
With _tag_delim = ':' &
_record_delim = '\n'
*/
  if (std::getline(
        _istream
      , buffer
      , _record_delim
      )
     ){
  auto itbegin = std::begin(buffer)
     , itend = std::end(buffer)
     , iter_value = std::find(
                      itbegin
                    , itend
                    , _tag_delim
                    );
  return basic_flag<
           charT
         , traits
         , allocator
         >(
           itbegin
         , iter_value
         , std::find(
             ++iter_value
           , itend
           , _tag_delim
           )
         , itend
         );
  }
throw std::runtime_error(
        "Could not determine tag, "
        "database stream is not well"
        " formatted."
      );
}

} /* forma */
#endif
