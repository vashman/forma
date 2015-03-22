// forma_database plugin implementation

#ifndef FORMA_FORMA_DATABASE_PLUGIN_HPP
#define FORMA_FORMA_DATABASE_PLUGIN_HPP

#include "database_plugin.hpp"
#include "database.hpp"

namespace forma {
/**/
template <typename charT, typename traits, typename targetT>
class forma_database_plugin : public database_plugin {
public:
  forma_database_plugin(
    std::basic_streambuf<charT,traits> *
  );

private:
  virtual bool
  do_get(
  );

  virtual bool
  do_get(
    targetT const &
  );

  database<charT,traits> dbmdl;
};

/* ctor */
template <typename charT, typename traits, typename targetT>
forma_database_plugin<charT,traits,targetT>::forma_database_plugin(
  std::basic_streambuf<charT,traits> * _buf
)
  : database_plugin (this->dbmdl)
  , dbmdl (_buf) {
}

/* do_get */
template <typename charT, typename traits, typename targetT>
bool
forma_database_plugin<charT,traits,targetT>::do_get(
) try {
this->dbmdl.next_target();
return true;
}
catch (...){
return false;
}

/* do_get */
template <typename charT, typename traits, typename targetT>
bool
forma_database_plugin<charT,traits,targetT>::do_get(
  targetT const & _target
) try {
this->database.next_target(_target);
return true;
}
catch (...){
return false;
}

} /* forma */
#endif
