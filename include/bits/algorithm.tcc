#ifndef ALGORITHM_ALFORITHM_TCC
#define ALGORITHM_ALGORITHM_TCC

namespace algorithm {

/* splice */
template <
  typename inputIt
, typename outputIt
, typename T
>
void
slice(
  inputIt _iter
, inputIt _end
, outputIt _output
, T const & const _delim
){
  while (
    (_iter != _end)
  &&
    (*_iter != _delim)
  ){
  _output = *_iter;
  ++iter;
  }
}

} /* algorithm */
#endif
