// forma lib header

//          Copyright Sundeep S. Sangha 2013 - 2015.

#ifndef FORMA_FORMA_HPP
#define FORMA_FORMA_HPP

#include <taxo/tag.hpp>
#include <taxo/relation.hpp>
#include <string>
#include <memory>
#include <data_pattern/data_model.hpp>

namespace forma {

typedef taxo::tag tag_t;
typedef std::string string_t;
typedef std::string target_t;
typedef taxo::relation<string_t> flag_t;

typedef
std::shared_ptr<
  data_pattern::data_model
>
context_t;

typedef
std::shared_ptr<
  data_pattern::data_model
>
database_t;

typedef 
pair<
  target_t
, idata_model_iterator<tag_t>
> dependent_t;

} /* forma */
#endif

