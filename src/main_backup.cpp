// Process forma dependency file in current context (complier, os, etc),
// and produce a build script via the combination of a template build
// script.

//          Copyright Sundeep S. Sangha 2013 - 2015.

#include <set>
#include <vector>
#include <stack>
#include <string>
#include <iterator>
#include <data_pattern/data_model.hpp>
#include "../include/forma.hpp"
using std::set;
using std::begin;
using std::end;
using std::vector;
using std::back_insert_iterator;
using std::ostream_iterator;
using std::istream_iterator;

using data_pattern::data_model;

using forma::char_t;
using forma::traits_t;
using forma::header;
using forma::load_header;
using forma::empty;
using forma::make_context;
using forma::make_formadb;
using forma::make_output;
using forma::make_input;
using forma::tag_t;
using forma::flag_t;
using forma::target_t;
using forma::context_t;
using forma::database_t;
using forma::ostream_t;
using forma::istream_t;
using forma::check_header;

enum class flags : char {
reverse,
simulate,
target,
filename
};

int main(int argc, char* argv[]) {

do {
db->next_depen();
do {
  if (
  is_any(
    tag_iter
  , tag_end
  , [context_begin, context_end](){
    return is_any(context_begin);
    }
  )){
  (target_list[*target_iter]->second)
  .push_back(*(++target_iter));
  }
db->next_depen();
} while (target_iter != target_end);
do->next_target(*target_iter);
target_list[*(++target_iter)] = vector();
} while (target_iter != target_end);



// output

ostream_t output (make_output());
  if (!output && !(*output))
  return 1;

istream_t bt (make_input());
  if (!build_template && !(*build_template))
  return 1;

istream_iterator<char_t> template_end;
istream_iterator<char_t> template_iter(
  (*build_template)
);

  if (!check_header())
  throw "Build template error.";
build_header head(load_header(template_iter));

output_until(
  template_iter
, template_end
, build_iter
, head.delim
);
output_until(
  template_iter
, template_end
, buff_insert
, head.delim
);

/////////////////////////////
auto
  context_begin(begin(context_tags))
, context_end(end(context_tags));
 
auto
  current_target (begin(target_list))
, end_current_target (end(target_list));

/* read through stream */
vector<char_t> buffer;
ostream_iterator<char_t> build_iter(
  (*build_file)
);
back_insert_iterator<vector<char_t> >
  buff_insert(buffer);

/* This assumes the next char is a tag
check delimiter.
*/
auto tag_iter
  = find_tag(
      std::begin(buffer)
    , std::end(buffer)
    , head.in
    , head.ex
    );
  if (validate_tag(
        tag_iter
      , begin(context_tags)
      , end(context_tags)
      , head.in
      , head.ex
      , tag_compare()
      )
    ){
  }
//////////////////////////////////////////////////////////////////
const int buffer_size = 127;
char_t iobuffer[buffer_size];

auto buffend (end(iobuffer)) /* end of entire buffer */
   , buffbegin (begin(iobuffer))
   , buffiter (begin(iobuffer)); /* current read position in buffer */

bool statement_begin = false
   , statement_middle = false;
/*
/ * read through stream * /
while (build_template.read(iobuffer, buffer_size)){
/ * This assumes the next char after buffmid is a tag cheack delimator. * /
auto tag_iter = find_tag(next(buffmid), buffend, head.in, head.ex);
  while (tag_iter != buffend) { / * Check the next tag can not be found. * /
    if (!validate_tag(*buffmid
                   , listbegin
                   , listend
                   , head.in
                   , head.ex
                   , tag_compare())
    ){ / * tag did not validate * /
    buffmid = buffend;
    statement_begin = buffend;
    tag_iter = buffend;
    continue;
    }
  tag_iter = find_tag(next(buffmid), buffend, head.in, head.ex);
  }
  if ((buffiter = find(tag_iter, buffend, head.delim)) != buffend){
  break;
  }

/ * lookup tag and replace value * /
build_file.stream << *(find_replacement(taglist_begin
                      , taglist_end
                      , default_subtag
                      , tag));
}*/
return 0;
}
