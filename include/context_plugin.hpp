// forma context data_model plugin

#ifndef FORMA_CONTEXT_PLUGIN_HPP
#define FORMA_CONTEXT_PLUGIN_HPP

#include <data_pattern/data_model.hpp>
#include "datamodel_plugin.hpp"

namespace forma {

class context_plugin : public datamodel_plugin {
public:
  context_plugin(
    data_pattern::data_model &
  );

  virtual
  ~context_plugin(
  );

  void
  get_tags(
  );

  void
  get_flags(
  );

protected:
  /* do_get_tags
  The returned bool value reports an error when set to false.
  nothrow
  */
  virtual bool
  do_get_tags(
  ) = 0;

  virtual bool
  do_get_flags(
  ) = 0;
};

} /* forma */
#endif
