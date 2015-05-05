// Process forma dependency file in current context (complier, os, etc),
// and produce a build script via the combination of a template build
// script.

//          Copyright Sundeep S. Sangha 2013 - 2014.

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
using std::basic_string;
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

typedef basic_string<
  forma::char_t
, forma::traits_t
> string_t;

enum class flags : char {
reverse,
simulate,
target,
filename
};

class compare_tag {
public:
  explicit
  compare_tag(
    tag_t const &
  );
  
  bool
  operator()(
  tag_t const &
  ) const;

private:
  tag_t const & tag;
};

int main(int argc, char* argv[]) {
bool direction = false; // io direction
bool output = true;

/* context information */
set<tag_t> context_tags;
set<flag_t> context_flags;

context_t context (make_context());
  if (!context){
  //fatal << "cout not create context database.";
  return 1;
  }
// Retrieve all context tags
context->get_tags();
copy(
  idata_model_iterator<tag_t>(context)
, idata_model_iterator<tag_t>()
, inserter(
    begin (context_tags)
  , end (context_tags)
  )
);

context->get_flags();
copy(
  idata_model_iterator<flag_t>(context)
, idata_model_iterator<flag_t>()
, inserter(
    begin (context_flags)
  , end (context_flags)
  )
);

database_t db (make_formadb());
  if (!db){
  return 1;
  }

db->next_target();
idata_model_iterator<target_t>
  db_end, db_begin(db);

  if (db_end != db_begin)
  return 1;

/* List of all targets loaded. */
map<target_t, vector<target_t> >
  target_list;

auto
  context_begin(begin(context_tags))
, context_end(end(context_tags));
 
/* Retrive vaild targets. */
for (
    auto iter(begin(target_list))
  ; db_begin != db_end
  ; db->next_target(), ++db_begin
){
iter = target_list.insert(*db_begin);
  if (
    !validate_target(
      begin(iter.first->tags)
    , end(iter.first->tags)
    , context_begin
    , context_end
    )
  ){
  /* remove target from list */
  target_list.remove(*iter);
  continue;
  }
/* Retrive targets
*/
db->next_dependency(*iter->first);
  for(
    auto depen_iter(
      back_inserter(iter->second)
    )
  ; db_begin != db_end
  ; ++db_begin
  ){
  dpen_iter = *db_begin;
  }
auto depeniter(begin(iter->second))
    , enditer(end(iter->second))

  while (depeniter != enditer){
    if (
      validate_target(
        depeniter
      , enditer
      , context_begin
      , context_end
      )
    ){
    ++depeniter
    continue;
    }
  depeniter
    = iter->second.erase(depeniter);
  }
}

  /* quit if not outputting */
  if (output == false){
  return 0;
  }

auto
  current_target (begin(target_list))
, end_current_target (end(target_list));

ostream_t build_file (make_output());
  if (!build_file && !(*build_file)){
  return 1;
  }
istream_t build_template (make_input());
  if (
    !build_template
  &&
    !(*build_template)
  ){
  return 1;
  }

istream_iterator<char_t> template_end;
istream_iterator<char_t> template_iter(
  (*build_template)
);

{ /* check header */
char_t const * const forma_header_string
  = "forma header:";
  if (
    !check_header(
      template_iter
    , template_end
    , forma_header_string
    , traits_t::length(
        forma_header_string
      )
    )
  ){
  return 1;  
  }
} /* check header */

header<char_t> head
  = load_header<char_t>(
      template_iter
    , template_end
    );

/* read through stream */
vector<char_t> buffer;
ostream_iterator<char_t> build_iter(
  (*build_file)
);
back_insert_iterator<vector<char_t> >
  buff_insert(buffer);

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

compare_tag::compare_tag(
  tag_t const & _tag
)
  : tag (_tag) {
}
  
bool
compare_tag::operator()(
  tag_t const & _tag
) const {
return (_tag.tag == this->tag.tag);
}
