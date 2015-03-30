//

//          Copyright Sundeep S. Sangha 2014 - 2015.

#ifndef FORMA_TAG_HPP
#define FORMA_TAG_HPP

#include <string>

namespace forma {
/**/
template <typename charT, typename traits, typename allocator>
struct basic_tag {
public:
  /* ctor */
  basic_tag(
  ) = default;

  /* ctor */
  template <typename InputIt>
  basic_tag(
    InputIt _first_tag
  , InputIt _last_tag
  , InputIt _first_root
  , InputIt _last_root
  );

  /* ctor */
  template <typename InputIt>
  basic_tag(
    InputIt _first
  , InputIt _delim
  , InputIt _last
  );

  /* copy ctor */
  basic_tag(
    basic_tag<charT,traits,allocator> const &
  );

  /* copy assignment */
  basic_tag<charT,traits,allocator> &
  operator=(
    basic_tag<charT,traits,allocator> const &
  );

  /* compare
  Compare tags and its root.
  */
  template <typename InputIt>
  bool
  compare(
    InputIt _first
  , InputIt _last
  , typename InputIt::value_type _delim
  );

  /* compare */
  template <typename InputIt>
  bool
  compare(
    InputIt _first_tag
  , InputIt _last_tag
  , InputIt _first_root
  , InputIt _last_root
  );

  bool
  operator<(
    basic_tag<charT,traits,allocator> const &
  ) const;

  std::basic_string<charT,traits,allocator> tag;
  std::basic_string<charT,traits,allocator> root;
};

/* basic_tag ctor */
template <typename charT, typename traits, typename allocator>
template <typename InputIt>
basic_tag<charT,traits,allocator>::basic_tag(
  InputIt _first_tag
, InputIt _last_tag
, InputIt _first_root
, InputIt _last_root
)
  : tag (_first_tag, _last_tag)
  , root (_first_root, _last_root) {
}

/**/
template <typename charT, typename traits, typename allocator>
template <typename InputIt>
basic_tag<charT,traits,allocator>::basic_tag(
  InputIt _first
, InputIt _delim
, InputIt _last
)
  : tag (_first, _delim)
  , root () {
  /*if (_delim != _last)*/ this->root.assign(_delim,_last);
//throw ;
}

/* copy_ctor */
template <typename charT, typename traits, typename allocator>
basic_tag<charT,traits,allocator>::basic_tag(
  basic_tag<charT,traits,allocator> const & _tag
)
  : tag (_tag.tag)
  , root (_tag.root) {
}

/**/
template <typename charT, typename traits, typename allocator>
basic_tag<charT,traits,allocator> &
basic_tag<charT,traits,allocator>::operator=(
  basic_tag<charT,traits,allocator> const & _tag
){
  if (this != &_tag){
  this->tag = _tag.tag;
  this->root = _tag.root;
  }
return *this;
}

/**/
template <typename charT, typename traits, typename allocator>
template <typename InputIt>
bool
basic_tag<charT,traits,allocator>::compare(
  InputIt _first
, InputIt _last
, typename InputIt::value_type _delim
){
// use std::equal ?
std::basic_string<charT,traits,allocator> s1(_first,_delim), s2((++_delim),_last);
return (this->tag.compare(s1) && this->root.compare(s2));
}

template <typename charT, typename traits, typename allocator>
bool
basic_tag<charT,traits,allocator>::operator<(
  basic_tag<charT,traits,allocator> const & _tag
) const {
return ((_tag.tag < this->tag) && (_tag.root < this->root));
}

/*
template <typename charT, typename traits, typename allocator>
std::basic_ostream<charT,triats> &
std::basic_ostream<charT,traits>::operator<<(
  std::basic_ostream<charT,traits> & _os
, basic_tag<charT,traits> const & _tag
){

}*/

} /* forma */
#endif
