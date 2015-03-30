//

#ifndef FORMA_FORMA_CONTEXT_PLUGIN_HPP
#define FORMA_FORMA_CONTEXT_PLUGIN_HPP

#include "context_plugin.hpp"
#include "context_datamodel.hpp"

namespace forma {
/* forma_context_datamodel */
template <
  typename charT
, typename traits
, typename tag_allocator = std::allocator<charT>
, typename flag_allocator = std::allocator<charT>
>
class forma_context_plugin : public context_plugin {
public:
  /* ctor */
  forma_context_plugin(
    std::basic_streambuf<charT,traits> *
  );

private:
  virtual bool
  do_get_tags(
  );

  virtual bool
  do_get_flags(
  );

  context_datamodel<charT,traits,tag_allocator,flag_allocator> dbmdl;
};

/* ctor */
template <
  typename charT
, typename traits
, typename tag_allocator
, typename flag_allocator
>
forma_context_plugin<charT,traits,tag_allocator,flag_allocator>
::forma_context_plugin(
  std::basic_streambuf<charT,traits> * _buf
)
 : context_plugin (this->dbmdl)
 , dbmdl (_buf) {
}

/**/
template <
  typename charT
, typename traits
, typename tag_allocator
, typename flag_allocator
>
bool
forma_context_plugin<charT,traits,tag_allocator,flag_allocator>
::do_get_tags(
) try {
this->dbmdl.get_tags();
return true;
} catch (...) {
return false;
}

/**/
template <
  typename charT
, typename traits
, typename tag_allocator
, typename flag_allocator
>
bool
forma_context_plugin<charT,traits,tag_allocator,flag_allocator>
::do_get_flags(
) try {
this->dbmdl.get_flags();
return true;
} catch (...) {
return false;
}

} /* forma */
//#include "./bits/forma_context_plugin.tcc"
#endif
