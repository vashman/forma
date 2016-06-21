// forma context data_model plugin

#ifndef FORMA_CONTEXT_HPP
#define FORMA_CONTEXT_HPP

#include <data_pattern/data_model.hpp>

namespace forma {

class context {
public:
  /* ctor */
  context(
    data_pattern::data_model &
  );

  /* dtor */
  virtual
  ~context(
  );

  /* get_tags */
  void
  get_tags(
  );

  /* get_flags */
  void
  get_flags(
  );

protected:
  /* do_get_tags
    The returned bool value reports an
    error when set to false.
  nothrow
  */
  virtual bool
  do_get_tags(
  ) = 0;

  /* do_get_flags
  */
  virtual bool
  do_get_flags(
  ) = 0;
};

} /* forma */
#endif
