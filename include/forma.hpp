// forma lib header

//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef FORMA_FORMA_HPP
#define FORMA_FORMA_HPP

#include <memory>
#include <istream>
#include <ostream>
#include <algorithm>
#include "forma_types.hpp" /* shared with plugin types */
#include "target.hpp"
#include "context_plugin.hpp"
#include "database_plugin.hpp"
#include "istream_plugin.hpp"
#include "ostream_plugin.hpp"
#include "data_model_shared.hpp"
//#define STATIC_FACTORY
//#include <factory_loader/factory_loader.hpp>

namespace forma {

//typedef factory_loader::static_factory factory_t;
typedef std::unique_ptr<ostream_plugin<char_t, traits_t> > ostream_t;
typedef std::unique_ptr<istream_plugin<char_t, traits_t> > istream_t;
typedef std::shared_ptr<datamodel_plugin> datamodel_t;
typedef std::shared_ptr<context_plugin> context_t;
typedef basic_target<char_t, traits_t, std::allocator<char_t>, std::allocator<char_t>, std::allocator<char_t> > target_t;
typedef std::shared_ptr<database_plugin<target_t> > database_t;

/* tag_compare functor */
/*template <typename InputIt>
class tag_compare {
public:
  tag_compare(
    InputIt begin
  , InputIt end
  );

  *//* compare functor operator */
  /*bool
  operator(
    tag_t
  );

private:
  begin, end;
};

*/
/*template <typename InputIt>
tag_compare<InputIt>::operator()(
  tag _tag
){
return _tag.compare(this->begin, this->end);
}*/

/* header */
template <typename charT>
class header {
public:
  bool reverse;
  charT delim /* new line delim */
  , target_sub /* current target subsistution token */
  , dependcy_sub /* current dependicy subsistution token */
  , block_delim; /* mark start and end of subsistution block */
};

/* load_header
  load forma header
*/
template <typename charT, typename inputIt>
header<charT>
load_header(
  inputIt _begin
, inputIt _end
){
header<charT> head;
if (_begin != _end) head.delim = *(++_begin);
if (_begin != _end) head.target_sub = *(++(++_begin));
if (_begin != _end) head.dependcy_sub = *(++(++_begin));
if (_begin != _end) head.block_delim = *(++(++_begin));
return head;
}

/* find tag in input stream segment */
template <typename InputIt>
InputIt
find_tag(
  InputIt _first
, InputIt _last
, typename InputIt::value_type const & _delim_inclusive
, typename InputIt::value_type const & _delim_exclusive
){
  if (*_first != _delim_inclusive || *_first != _delim_exclusive){
  return _last;
  }
InputIt iter(std::find(_first, _last, _delim_inclusive));
  if (iter != _last) return iter;
return std::find(_first, _last, _delim_exclusive);
}

/* Check if _flag is enabled or disabled. */
template <typename InputIt, typename Predicate>
bool
validate_tag(
  typename InputIt::vlaue_type _flag
, InputIt _list_first
, InputIt _list_last
, typename InputIt::value_type const & _delim_inclusive
, typename InputIt::value_type const & _delim_exclusive
, Predicate _pred
){
  if (_flag == _delim_inclusive){
  return std::any_of(_list_first, _list_last, _pred);
  } else if (_flag == _delim_exclusive){
  return std::none_of(_list_first, _list_last, _pred);
  }
return false;
}

/* return a replacement value for a tag */
template <typename InputIt, typename charT, typename traits, typename tagalloc>
InputIt
find_replacement(
  InputIt _first
, InputIt _last
, InputIt & _default
, forma::basic_tag<charT,traits,tagalloc> const & _tag
){
_first = std::find(_first, _last, _tag);
  if (_first != _last){
  return _first;
  }
return _default;
}

/* Factory functions for creating plugin types.  */

database_t 
make_formadb();

context_t
make_context();

istream_t
make_input();

ostream_t
make_output();

} /* forma */
#endif
