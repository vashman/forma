// Read context data from forma data
// base file,

#ifndef FORMA_CONTEXT_DATAMODEL_HPP
#define FORMA_CONTEXT_DATAMODEL_HPP

#include <vector>
#include <data_pattern/data_model.hpp>
#include "data_model_shared.hpp"
#include "forma_context.hpp"

namespace forma {
/* context_datamodel */
template <
  typename streamT
, typename tagT
, typename flagT
>
class context_datamodel
  : public data_pattern::data_model {
public:
  /* ctor */
  template <
    typename tag_container
      = std::vector<tagT>
  , typename flag_container
      = std::vector<flagT>
  , typename streambufT
  >
  context_datamodel(
    streambufT
  );

  /* dtor */
  ~context_datamodel(
  );

  /* get_tags */
  void
  get_tags(
  );

  /* get_flags */
  void
  get_flags(
  );

private:
  streamT stream;

  basic_context_header<
    typename streamT::char_type
  >
  header;
};

} /* forma */

#include "./bits/context_datamodel.tcc"
#endif
