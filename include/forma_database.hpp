//

#ifndef FORMA_FORMA_DATABASE_HPP
#define FORMA_FORMA_DATABASE_HPP

#include <istream>
#include <string>
#include <utility>

namespace forma {
/* database_header */
template <typename charT>
struct basic_database_header {
  charT comment_delim = '#';
  charT tag_delim = '@';
  charT tag_seperator_delim = ':';
  charT sub_element_delim = '\t';
  charT delim = '\n';
};

/**/
template <typename charT, typename traits>
basic_database_header<charT>
get_database_header(
  std::basic_istream<charT,traits> &
);

/* is_tag
Checks from the current stream position if the next line is a tag by
checking the next character.
*/
template <typename charT, typename traits>
bool
is_tag(
  std::basic_istream<charT,traits> &
, charT const _tag_delim
);

/* get_tag
retrieves the next element as a tag.
*/
template <typename charT, typename traits, typename alloc>
basic_tag<charT,traits,alloc>
get_tag(
  std::basic_istream<charT,traits> &
, charT const _tag_seperator_delim
, charT const _end_delim
);

/* is_sub_element
Checks whether the next element is a sub-element of the last record.
*/
template <typename charT, typename traits>
bool
is_sub_element(
  std::basic_istream<charT,traits> &
, charT const _sub_element_delim
);

/* get_sub_element */
template <typename charT, typename traits, typename alloc>
std::basic_string<charT,traits,alloc>
get_sub_element(
  std::basic_istream<charT,traits> &
, charT const _end_delim
);

} /* forma */
#include "./bits/forma_database.tcc"
#endif
