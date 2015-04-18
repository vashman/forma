// forma context data_model

#ifndef FORMA_CONTEXT_DATAMODEL_HPP
#define FORMA_CONTEXT_DATAMODEL_HPP

#include <streambuf>
#include <istream>
#include <vector>
#include <data_pattern/data_model.hpp>
#include <taxo/tag.hpp>
#include "flag.hpp"
#include "data_model_shared.hpp"
#include "forma_context.hpp"

namespace forma {
/* context_datamodel */
template <
  typename charT
, typename traits
, typename tag_allocator = std::allocator<charT>
, typename flag_allocator = std::allocator<charT>
>
class context_datamodel : public data_pattern::data_model {
public:
  /*ctor*/
  template <
    typename tag_container = std::vector<
               taxo::basic_tag<charT,traits,tag_allocator> >
  , typename flag_container = std::vector<
               basic_flag<charT,traits,flag_allocator> >
  >
  context_datamodel(
    std::basic_streambuf<charT,traits> *
  ); 

  /*dtor*/
  ~context_datamodel(
  );

  void
  get_tags(
  );

  void
  get_flags(
  );

private:
  std::basic_istream<charT,traits> stream;

  basic_context_header<charT> header;
};

} /* forma */

#include "./bits/context_datamodel.tcc"
#endif