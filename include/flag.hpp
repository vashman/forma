// flag = tag + value for the tag

#ifndef FORMA_FLAG_HPP
#define FORMA_FLAG_HPP

#include <string>
#include "tag.hpp"

namespace forma {
/**/
template <typename charT, typename traits, typename allocator>
class basic_flag : public basic_tag<charT,traits,allocator> {
public:
  basic_flag() = default;

  template <typename InputIt>
  basic_flag(
    InputIt _tag_begin
  , InputIt _tag_end
  , InputIt _root_end
  , InputIt _value_end
  )
  : basic_tag<charT,traits,allocator> (_tag_begin, _tag_end, _tag_end, _root_end)
  , value (_root_end, _value_end) {
  }

  bool
  operator<(
    basic_flag<charT,traits,allocator> const &
  ) const;

  std::basic_string<charT,traits,allocator> value;
};

/* operator < */
template <typename charT, typename traits, typename allocator>
bool
basic_flag<charT,traits,allocator>::operator<(
  basic_flag<charT,traits,allocator> const & _flag
) const {
return ((_flag.value < this->value) && (_flag < *this));
}

} /* forma */
#endif
