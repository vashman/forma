// data model for to forma file.

//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef FORMA_DATABASE_HPP
#define FORMA_DATABASE_HPP

#include <vector>
#include <typesystems/.hpp>
#include <data_pattern/data_model.hpp>
#include "data_model_shared.hpp"
#include "forma_database.hpp"

namespace forma {
/* database */
template <
  typename targetT
, typename istreamT
>
class database
: public data_pattern::data_model {
public:
  typedef typename istreamT::char_type
  char_type;

  typedef typename targetT::tag_type
  tag_type;

  /* ctor */
  template <typename streambufT>
  database(
    streambufT *
  );

  /* dtor */
  ~database() = default;

  /* next_target */
   void
   next_target(
   );

   /* next_target
      The targetT is any type comparable
      to basic_target<>::target_type
   */
   template <typename targetT>
   void
   next_target(
     targetT const &
   );

private:
  istreamT stream;

  basic_database_header<char_type>
  header;

  targetT temp_target;

  std::vector<targetT> target_buffer;
};

/* forma::database */
template <
  typename targetT
, typename istreamT
>
template <typename streambufT>
database<targetT,istreamT>::database(
  streambufT * _buffer
)
: stream (_buffer)
, header (
    get_database_header(this->stream)
  )
, temp_target ()
, buffer () {

  typesystems
::set_typebuffer<
  targetT
, typebuffer_queue<targetT>
>(this->buffer);
}

/* next_target
*/
template <
  typename targetT
, typename istreamT
>
void
database<targetT,istreamT>::next_target(
){
auto &
target_container = typesystems
::use_typebuffer<targetT>(
this->buffer
);

std::vector<tag_type> tag_buffer;

std::getline(
  this->stream
, this->temp_target.target
, this->header.delim
);
  while (
    is_sub_element(
      this->stream
    , this->header.sub_element_delim
    )
  ){
  this->stream.get();
    if (
      is_tag(
        this->stream
      , this->header.tag_delim
      )
    ){
    this->stream.get();
    tag_buffer.push_back(
      get_tag<charT,traits,tag_allocator>(
        this->stream
      , this->header.tag_seperator_delim
      , this->header.delim
      )
    );
    continue;
    }
  this->temp_target.dependencies[
    get_sub_element<charT,traits,allocator>
     (this->stream, this->header.delim)] = tag_buffer;
  }
target_container.push(this->temp_target);
}

/* next_target */
template <
  typename targetT
, typename istreamT
>
template <typename targetT>
void
database<targetT,istreamT>::next_target(
  targetT const & _target
){
auto & target
= typesystems::use_typebuffer<targetT>
(this->typesys);

this->next_target();
this->temp_target = target.next();
    if (this->temp_target == _target){
    target.push(this->temp_target);
    return;
    } else {
    this->buffer.push_back(this->temp_target);
    }
/* search previous unused targets for a match. */
auto iter (begin(this->buffer)), iend(end(this->buffer)); 
while (iter != iend){
  if (same_target(*iter, _target)){
  target.push(*iter);
  this->buffer.erase(iter);
  return;
  }
}
}

} /* forma */
#endif
