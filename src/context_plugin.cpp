// forma context data_model plugin

#ifndef FORMA_CONTEXT_PLUGIN_CPP
#define FORMA_CONTEXT_PLUGIN_CPP

#include "../include/context_plugin.hpp"

namespace forma {

/* ctor */
context_plugin::context_plugin(
  data_pattern::data_model & _db
)
  : datamodel_plugin (_db) {
}

/* dtor */
context_plugin::~context_plugin(
){
}

/* context_plugin get_tags */
void
context_plugin::get_tags(
){
this->do_get_tags();
}

/* context_plugin get_flags */
void
context_plugin::get_flags(
){
this->do_get_flags();
}

} /* forma */
#endif
