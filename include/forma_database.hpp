//

#ifndef FORMA_FORMA_DATABASE_HPP
#define FORMA_FORMA_DATABASE_HPP

#include <istream>
#include <string>
#include <utility>

namespace forma {
/**/
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
get_header(
  std::basic_istream<charT,traits> &
);

/**/
template <typename charT, typename traits, typename alloc>
bool
get_tag(
  std::basic_istream<charT,traits> &
, basic_tag<charT,traits,alloc> &
, charT const _sub_delim
, charT const _tag_delim
, charT const _tag_seperator_delim
, charT const _delim
);

/**/
template <typename charT, typename traits, typename alloc>
bool
get_sub_element(
  std::basic_istream<charT,traits> &
, std::basic_string<charT,traits,alloc> &
, charT const
, charT const
);

} /* forma */
#include "./bits/forma_database.tcc"
#endif
