//

#ifndef FORMA_DATABASE_PLUGIN_HPP
#define FORMA_DATABASE_PLUGIN_HPP

#include <data_pattern/data_model.hpp>
#include "./datamodel_plugin.hpp"

namespace forma {
template <typename targetT>
class database_plugin
  : public datamodel_plugin {
public:
  /* ctor */
  database_plugin(
    data_pattern::data_model &
  );

  /* dtor */
  virtual
  ~database_plugin(
  );

  /**/
  void
  next_target(
    targetT const &
  );

  /**/
  void
  next_target(
  );

protected:
  virtual bool
  do_next_target(
  ) = 0;

  virtual bool
  do_next_target(
    targetT const &
  ) = 0;
};

/* database_plugin ctor */
template <typename targetT>
database_plugin<targetT>::database_plugin(
  data_pattern::data_model & _db
)
  : datamodel_plugin (_db) {
}

/* database_plugin dtor */
template <typename targetT>
database_plugin<targetT>::~database_plugin(
){
}

/* database_plugin get_ */
template <typename targetT>
void
database_plugin<targetT>::next_target(
){
  if (false == this->do_next_target()){
  throw ;
  }
}

template <typename targetT>
void
database_plugin<targetT>::next_target(
  targetT const & _target
){
  if (false == this->do_next_target(_target)){
  throw ;
  }
}

} /* forma */
#endif
