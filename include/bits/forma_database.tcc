//

#ifndef FORMA_FORMA_DATABASE_TCC
#define FORMA_FORMA_DATABASE_TCC

#include <istream>
#include <string>

namespace forma {
/* get header */
template <typename charT, typename traits>
basic_database_header<charT>
get_database_header(
  std::basic_istream<charT,traits> & _istream
){
charT const * const header_string = "forma:";
std::streamsize const header_size = 22;
charT buffer[header_size];
_istream.getline(buffer, header_size, '\n');
  if (0 != traits::compare(buffer, header_string
     , traits::length(header_string))){
  throw std::runtime_error("header does not compare");
  }
basic_database_header<charT> header;
  switch (traits::length(buffer)){
  case 16:
  header.delim = buffer[16];
  case 14:
  header.sub_element_delim = buffer[14];
  case 12:
  header.tag_seperator_delim = buffer[12];
  case 10:
  header.tag_delim = buffer[10];
  case 8:
  header.comment_delim = buffer[8];
  break;
  default:
  std::cerr << traits::length(buffer);
  throw std::runtime_error("Header not parsable due to size differnce.");
  }
return header;
}

/* is_tag */
template <typename charT, typename traits>
bool
is_tag(
  std::basic_istream<charT,traits> & _is
, charT const _tag_delim
){
return (_is.peek() != traits::to_int_type(_tag_delim));
}

/* is_sub_element */
template <typename charT, typename traits>
bool
is_sub_element(
  std::basic_istream<charT,traits> & _is
, charT const _sub_element_delim
){
return (_is.peek() != traits::to_int_type(_sub_element_delim));
}

/* get_sub_element */
template <typename charT, typename traits, typename alloc>
std::basic_string<charT,traits,alloc>
get_sub_element(
  std::basic_istream<charT,traits> & _is
, charT const _end_delim
){
std::basic_string<charT,traits,alloc> buffer;
  if (!std::getline(_is, buffer, _end_delim)){
  throw ;
  }
return buffer;
}

} /* forma */
#endif
