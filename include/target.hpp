//

#ifndef FORMA_TARGET_HPP
#define FOMRA_TARGET_HPP

#include <string>

namespace forma {
/**/
template <
  typename charT
, typename traits = std::char_traits<charT>
, typename allocator = std::allocator<charT>
, typename flag_allocator = std::allocator<charT>
, typename tag_allocator = std::allocator<charT>
>
class basic_target{
public:
  typedef std::vector<std::basic_tag<charT,traits,flag_allocator,tag_allocator> > tags_t;

  basic_target() = default;

  template <typename InputIt, typename InputItVec>
  basic_target(
    InputIt _begin_target
  , InputIt _end_target
  , InputItVec _begin
  , InputItVec _end
  );

  std::basic_string<charT,traits,allocator> target;
  std::map<std::basic_string<charT,traits,allocator>, tags_t> dependices;
};

template <typename InputIt, typename InputItVec>
basic_target(
  InputIt _begin_target
, InputIt _end_target
, InputItVec _begin
, InputItVec _end
)
 : target (_begin_target, _end_target)
 , dependices (_begin, _end) {
}

} /* forma */
#endif
