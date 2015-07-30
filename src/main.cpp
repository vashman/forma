// Process forma dependency file in current context (complier, os, etc),
// and produce a build script via the combination of a template build
// script.

//          Copyright Sundeep S. Sangha 2013 - 2015.

#include <algorithm>
#include <set>
#include <vector>
#include "../include/forma.hpp"
#include <data_pattern/iterator.hpp>

#include <data_pattern/sqlite.hpp>
#include "tag_iwriter.cpp"

using std::back_inserter;
using std::vector;
using std::set;
using std::copy;
using data_pattern::data_model;
using
data_pattern::idata_model_iterator;
using forma::tag_t;
using forma::context_t;

data_model *
make_context();

data_model *
make_formadb();

void
delete_context(data_model *);

void
next_target();

void
get_tags();

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

  if (!context)
//  log<true>(fatal, ) << "cout not create context database.";
  return 1;

// Retrieve all context tags
get_tags();
copy(
  idata_model_iterator<tag_t>(
    * context.get()
  )
, idata_model_iterator<tag_t>()
, back_inserter(context_tags)
);

database_t db (make_formadb());
  if (!db)
  return 1;

next_target();
idata_model_iterator<target_t>
  target_end, target_iter(db);

  if (target_end == target_iter)
  return 1;

return 0;
}

data_model *
make_context(){
data_model * db = new data_pattern::sqlite("onion.sqlite");
  if (! db->set_iwriter<tag_iwriter>())
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
delete_context(data_model * _db){
delete _db;
}
