// Process forma dependency file in current context (complier, os, etc),
// and produce a build script via the combination of a template build
// script.

//          Copyright Sundeep S. Sangha 2013 - 2015.

#include <algorithm>
#include <set>
#include <vector>
#include <set>
#include "../include/forma.hpp"
#include <data_pattern/cast_iterator.hpp>

using std::back_inserter;
using std::vector;
using std::set;
using std::copy;
using iterator_decorator::cast_iterator;

using forma::tag_t;
using forma::make_context;
using forma::make_forma;
using forma::make_output;

int main(int argc, char* argv[]) {
bool output = true;

// The container will remove all duplicates.
set<tag_t> context_tag;
{ // Retrieve context tags
auto context (make_contxet());
sync(context);
copy (
  cast_iterator<tag_t>(begin(context))
, cast_iterator<tag_t>(end(context))
, back_inserter(context_tag)
);
}

vector<target_t> target;
{ // Load targets and filter out dependencies
auto db (make_forma());
sync(db);
for (auto const& dependency : db){
  if (find (begin(context_tag), end(context_tag), dependency) != end(context_tag))
  copy(begin(db), end(db), back_inserter(target));
next_target(db);
sync(db);
}
}

  if (output == false) return 0;
vector<tuple<tag_t,tag_t>> tag_map;
// Read in output tags and map to...
auto tag (make_tag());
for (tag_t const & value : tag){
  if (find (begin(context_tag), end(context_tag), value) != end(context_tag))
  copy(begin(tag), end(tag), back_inserter(tag_map));
next_tag(tag);
sync(tag);
}

auto make (make_output());

return 0;
}
