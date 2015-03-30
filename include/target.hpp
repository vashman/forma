// holds associations between targets & dependences

//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef FORMA_TARGET_HPP
#define FORMA_TARGET_HPP

#include <string>
#include "tag.hpp"

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
  typedef std::vector<
    basic_tag<charT,traits,tag_allocator> > tags_t;
  typedef std::basic_string<charT,traits,allocator> dependency;
  typedef std::map<dependency, tags_t> dependency_container;

  /* ctor */
  basic_target(
  ) = default;

  /* ctor */
  template <typename InputIt, typename InputItVec>
  basic_target(
    InputIt _begin_target
  , InputIt _end_target
  , InputItVec _begin
  , InputItVec _end
  );
  
  std::basic_string<charT,traits,allocator> target;
  std::map<dependency, tags_t> dependencies;
};

template <
  typename charT, typename traits, typename allocator
, typename flag_allocator, typename tag_allocator>
bool
same_target(
  basic_target<charT,traits,allocator,flag_allocator,tag_allocator> const &
, basic_target<charT,traits,allocator,flag_allocator,tag_allocator> const &
);

/* target ctor */
template <
  typename charT
, typename traits
, typename allocator
, typename flag_allocator
, typename tag_allocator
>
template <typename InputIt, typename InputItVec>
basic_target<charT,traits,allocator,flag_allocator,tag_allocator>
::basic_target(
  InputIt _begin_target
, InputIt _end_target
, InputItVec _begin
, InputItVec _end
)
 : target (_begin_target, _end_target)
 , dependencies (_begin, _end) {
}

template <
  typename charT, typename traits, typename allocator
, typename flag_allocator, typename tag_allocator>
bool
same_target(
  basic_target<charT,traits,allocator,flag_allocator,tag_allocator> const & _target
, basic_target<charT,traits,allocator,flag_allocator,tag_allocator> const & _other
){
return (_target.target == _other.target);
}

} /* forma */
#endif
