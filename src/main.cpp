// Process forma dependency file in current context (complier, os, etc),
// and produce a build script via the combination of a template build
// script.

//          Copyright Sundeep S. Sangha 2013 - 2015.

#include <algorithm>
#include <set>
#include <vector>
#include "../include/forma.hpp"
#include <data_pattern/cast_iterator.hpp>

using std::back_inserter;
using std::vector;
using std::copy;
using iterator_decorator::cast_iterator;

using forma::tag_t;
using forma::make_context;
using forma::make_forma;
using forma::make_output;

int main(int argc, char* argv[]) {
/* If true, output the result to output
  the output stream.
*/
bool output = true;

/* context information
  The container will remove all
  duplicates.
*/
vector<tag_t> context_tag;
vector<target_t> target;

auto context (make_contxet());
// Retrieve all context tags
sync(context);
copy (
  cast_iterator<tag_t>(begin(context))
, cast_iterator<tag_t>(end())
, back_inserter(context_tag)
);

auto db (make_forma()));
sync(db);
for (auto const& dependecy : db){
  if (find (begin(context_tag), end(context_tag), dependecy) != end(context_tag))
  copy(begin(db), end(db), back_inserter(target));
next_target(db);
sync(db);
}

  if (output == false) return 0;
auto make (make_output());

return 0;
}
