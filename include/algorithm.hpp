// Generic algorithms'

#ifndef ALGORITHM_ALGORITHM_HPP
#define ALGORITHM_ALGORITHM_HPP

namespace algorithm {

/* splice */
template <
  typename inputIt
, typename outputIt
, typename T = inputIt::value_type
>
void
slice(
  inputIt
, inputIt
, outputIt 
, T const & const 
);

template <
  typename inputIt
, typename Tag = taxo::tag
>
Tag
get_tag(
  inputIt _iter
, inputIt _end
);

} /* forma */
#include "bits/algorithm.tcc"
#endif
