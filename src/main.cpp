// Process forma dependency file in current context (complier, os, etc),
// and produce a build script via the combination of a template build
// script.

//          Copyright Sundeep S. Sangha 2013 - 2014.

#include <set>
#include <stack>
#include <string>
#include <iterator>
#include <data_pattern/data_model.hpp>
#include "../include/forma.hpp"
using std::set;
using std::begin;
using std::end;
using std::basic_string;

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

typedef basic_string<forma::char_t, forma::traits_t> string_t;

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
{ /* find context */
context_t context (make_context());
  if (!context){
  //fatal << "cout not create context database.";
  return 1;
  }
// Retrieve all context tags
context->get_tags();
{ /* get tags */
tag_t temp_tag;
	while (!empty<tag_t>(context)){
	context >> temp_tag;
  context_tags.insert(temp_tag);
	}
} /* get tags*/
{ /* get flags */
flag_t temp_flag;
  while(!empty<flag_t>(context)){
  context >> temp_flag;
  context_flags.insert(temp_flag);
  }
} /* get flags */
} /* find context */

database_t db (make_formadb());
  if (!db){
  return 1;
  }

db->next_target();
/* List of all targets loaded. */
std::vector<target_t> target_list;
/* queue of the next dependency of the current target to look up. */
std::stack<target_t::dependency_container::key_type> target_queue;
auto iter_tags(begin(context_tags)), iend_tags(end(context_tags));
for (target_t temp_target
    ; !empty<target_t>(db)
    ; temp_target.target = target_queue.top(), db->next_target(temp_target), target_queue.pop()
){
db >> temp_target;
auto dependency_iter(begin(temp_target.dependencies))
   , dependency_iend(end(temp_target.dependencies));
  while (dependency_iter != dependency_iend){
  auto iter(begin((*dependency_iter).second)), iend(end((*dependency_iter).second));
  while (iter != iend){
    /* filter next targets via tags */
    if (std::find_if(iter_tags, iend_tags, compare_tag(*iter)) != iend_tags){
    target_queue.push((*dependency_iter).first);
    break;
    }
  ++iter;
  }
    if (iter == iend){
    /* update the target list if dependency is not used. */
    temp_target.dependencies.erase(dependency_iter);
    }
  }
target_list.push_back(temp_target);
}

  /* quit if not outputting */
  if (output == false){
  return 0;
  }

auto current_target (begin(target_list))
  , end_current_target (end(target_list));

ostream_t build_file = make_output();
  if (!build_file && !(*build_file).stream){
  return 1;
  }
istream_t build_template = make_input();
  if (!build_template && !(*build_template).stream){
  return 1;
  }

std::istream_iterator<char_t> template_end;
std::istream_iterator<char_t> template_iter((*build_template).stream);
{ /* check header */
char_t const * const forma_header_string = "forma header:";
  if (!check_header(
    template_iter
  , template_end
  , forma_header_string
  , traits_t::length(forma_header_string)
  )){
  return 1;  
  }
} /* check header */
header<char_t> head = load_header<char_t>(template_iter, template_end);

string_t buffer; // used to hold generated output
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
  if (statement_begin == false){
  buffiter = find(buffbegin, buffend, head.delim);
  build_file.stream.write(*buffbegin
                        , std::distance(buffbegin, buffiter));
    if (buffiter == buffend) continue;
  statement_begin = true;
  }
  if (statement_middle == false){
  buffer.append(buffiter, buffend);
  auto iend = cend(buffer);
  auto iter = find(begin(buffer), iend, head.delim);
    if (statement_middle = (iter == iend)) continue;
  tag.assign(iter, iend);
  buffer.erase(iter, iend);
  }
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
