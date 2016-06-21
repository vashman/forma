// Holds the associations between
// targets and their dependences.

//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef FORMA_TARGET_HPP
#define FORMA_TARGET_HPP

#include <vector>

namespace forma {
/**/
template <
  typename stringT
, typename tagT
>
class basic_target{
public:
  typedef tagT tag_type;
  typedef stringT string_type;

  /* ctor */
  basic_target(
  ) = default;

  /* ctor */
  basic_target(
    stringT const &
  );
  
  stringT name;

  std::vector<tagT> dependencies;
};

/* target ctor */
template <
  typename stringT
, typename tagT
>
basic_target<stringT, tagT>
::basic_target(
  stringT const & _str
)
 : name (_str)
 , dependencies () {
}

} /* forma */
#endif
