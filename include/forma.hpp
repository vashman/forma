// forma lib header

//          Copyright Sundeep S. Sangha 2013 - 2015.

#ifndef FORMA_FORMA_HPP
#define FORMA_FORMA_HPP

#include <taxo/tag.hpp>
#include <taxo/relation.hpp>
#include <string>

namespace forma {

typedef taxo::tag tag_t;
typedef std::string target_t;
typedef taxo::relation<string_t> flag_t;

enum class event {
  subsitute_tag
, subsitute_target
, subsitute_dependency
, opening
, closing
};

make_context();
make_forma();
make_tag();
make_output();

} /* forma */
#endif

