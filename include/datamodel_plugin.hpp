// base class for data_model plugins

#ifndef FORMA_DATAMODEL_PLUGIN_HPP
#define FORMA_DATAMODEL_PLUGIN_HPP

#include <memory>
#include <data_pattern/data_model.hpp>

namespace forma {

/* datamodel_plugin */
class datamodel_plugin {
public:
  /* ctor */
  datamodel_plugin(
    data_pattern::data_model &
  );

  /* dtor */
  virtual
  ~datamodel_plugin(
  );

  /* */
  operator data_pattern::data_model &(
  ) const ;

protected:
  /**/
  data_pattern::data_model & db;
};

/* datamodel_plugin ctor */
datamodel_plugin::datamodel_plugin(
  data_pattern::data_model & _db
)
  : db(_db){
}

/* datamodel_plugin empty */
template <typename T>
bool
empty(
  std::shared_ptr<datamodel_plugin> _mdl
){
return data_pattern::empty<T>(_mdl->db);
}

/* forma datamodel_plugin << */
template <typename T>
data_pattern::data_model &
operator<<(
  std::shared_ptr<datamodel_plugin> _mdl
, T const _var
){
return operator<<(_mdl->db, _var);
}

/* forma datamodel_plugin >> */
template <typename T>
data_pattern::data_model &
operator>>(
  std::shared_ptr<datamodel_plugin> _mdl
, T & _var
){
return operator>>(_mdl->db, _var);
}

/**/
template <typename T>
datamodel_plugin<T>::operator
  data_pattern::data_model &(
){
return this->db;
}

} /* forma */
#include "bits/datamodel_plugin.hpp"
#endif
