// Process forma dependency file in current context (complier, os, etc),
// and produce a build script via the combination of a template build
// script.

//          Copyright Sundeep S. Sangha 2013 - 2015.

#include <algorithm>
#include <map>
#include <vector>
#include "../include/forma.hpp"
#include <iterator_decorator/iterator.hpp>
#include <data_pattern/iterator.hpp>

#include <data_pattern/sqlite.hpp>
#include "tag_iwriter.cpp"
#include "relation_iwriter.cpp"

using std::back_inserter;
using std::vector;
using std::set;
using std::map;
using std::copy;
using std::pair;
using data_pattern::data_model;
using
data_pattern::idata_model_iterator;
using forma::tag_t;
using forma::flag_t;
using forma::context_t;
using forma::database_t;
using forma::target_t;

data_model *
make_context();

data_model *
make_formadb();

void
delete_context(data_model *);

void
get_flag();

void
get_tag();

void
next_target();

void
next_target(target_t const &);

int main(int argc, char* argv[]) {
/* If true, output the result to output
  the output stream.
*/
bool output = true;

/* context information
  The container will remove all
  duplicates.
*/
vector<tag_t> context_tags;

context_t context (make_context());
  if (!context) return 1;

// Retrieve all context tags
copy(
  begin<tag_t>(
    * context.get()
  , get_tag()
  , iter_ops::increment
  )
, end<tag_t>(
    * context.get()
  , iter_ops::none
  )
, back_inserter<tag_t>(context_tags)
);

database_t db (make_formadb());
  if (!db) return 1;

/* List of all targets loaded. */
map <target_t, vector<target_t> >
target_list;

for (
  auto
    target_iter ( begin<target_t>(
      * db.get()
    , get_target()
    , iter_ops::increment
    ))
  , target_end ( end<target_t>(
      * db.get()
    , get_target()
    , iter_ops::none
    ))
; target_iter != target_t
; ++target_iter
){
target_list[*target_iter];
copy_if(
  begin<dependent_t>(
    * db.get()
  , get_dependent(*target_iter)
  , iter_ops::increment
  )
, end<dependent_t>(
    * db.get()
  , get_dependent()
  , iter_ops::none
  )
, back_inserter<target_t>(
    target_list[].second()
  )
, filter_dependent(
    begin<tag_t>(context_tags)
  , end<tag_t>(context_tags)
  )
);
}
  /* quit if not outputting */
  if (output == false) return 0;

vector<flag_t> context_flags;

copy(
  begin<flag_t>(
    * context.get()
  , get_flag
  , iter_ops::increment
  )
, end<flag_t>(
    * context.get()
  , get_flag
  , iter_ops::increment
  )
, back_inserter<flag_t>(context_flags)
);

return 0;
}

data_model *
make_context(){
data_model * db = new data_pattern::sqlite("onion.sqlite");
  if (
    ! db->set_iwriter<tag_iwriter>()
  ||
    ! db->set_iwriter<
        relation_iwriter<flag_t>
      >()
  )
  throw "iwriter error";
return db;
}

data_model *
make_formadb(){
data_model * db = new data_pattern::sqlite("onion.sqlite");
  if (! db->set_iwriter<tag_iwriter>())
  throw "iwriter error";
return db;
}

void
get_tags(){
}

void
next_target(){
}

void
next_target(
  target_t const &
){
}

void
next_target(){
}

void
get_flags(){
}

void
delete_context(data_model * _db){
delete _db;
}
