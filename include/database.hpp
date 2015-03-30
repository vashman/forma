// data model for to forma file.

//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef FORMA_DATABASE_HPP
#define FORMA_DATABASE_HPP

#include <streambuf>
#include <istream>
#include <vector>
#include <typesystems/typesystem.hpp>
#include <data_pattern/data_model.hpp>
#include "target.hpp"
#include "forma_database.hpp"

namespace forma {
/* database */
template <
  typename charT
, typename traits
, typename allocator = std::allocator<charT>
, typename tag_allocator = std::allocator<charT>
, typename flag_allocator = std::allocator<charT>
, typename targetContainer = std::vector<basic_target
    <charT,traits,allocator,tag_allocator,flag_allocator> >
>
class database : public data_pattern::data_model {
public:
  typedef basic_target<charT,traits,allocator
            ,tag_allocator,flag_allocator> target_type;

  database(
    std::basic_streambuf<charT,traits> *
  );

  ~database() = default;

   void
   next_target(
   );

   /* next_target
      The targetT is any type comparable to basic_target<>::target_type
   */
   template <typename targetT>
   void
   next_target(
     targetT const &
   );

private:
  std::basic_istream<charT,traits> stream;

  basic_database_header<charT> header;

  basic_target<charT,traits,tag_allocator> temp_target;

  std::vector<target_type> buffer;
};

/* forma::database */
template <
  typename charT
, typename traits
, typename allocator
, typename tag_allocator
, typename flag_allocator
, typename targetContainer
>
database<charT,traits,allocator,tag_allocator,flag_allocator
,targetContainer>
::database
(
  std::basic_streambuf<charT,traits> * _buffer
)
  : stream (_buffer)
  , header (get_database_header(this->stream))
  , temp_target ()
  , buffer () {
/* set buffer for tags as forma::target */
typesystems::set_typebuffer<
  basic_target<charT,traits,allocator,tag_allocator,flag_allocator>
, targetContainer>
(this->typesys);
}

/* next_target
*/
template <
  typename charT
, typename traits
, typename allocator
, typename tag_allocator
, typename flag_allocator
, typename targetContainer
>
void
database<charT,traits,allocator,tag_allocator,flag_allocator
,targetContainer>
::next_target(
){
auto & target_container
  = typesystems::use_typebuffer<basic_target<charT,traits,allocator> >
  (this->typesys);
std::vector<basic_tag<charT,traits,allocator> > tag_buffer;

std::getline(this->stream, this->temp_target.target, this->header.delim);
  while (is_sub_element(this->stream, this->header.sub_element_delim)){
  this->stream.get();
    if (is_tag(this->stream, this->header.tag_delim)){
    this->stream.get();
    tag_buffer.push_back(get_tag<charT,traits,tag_allocator>(
        this->stream
      , this->header.tag_seperator_delim
      , this->header.delim));
    continue;
    }
  this->temp_target
   .dependencies[get_sub_element<charT,traits,allocator>
     (this->stream, this->header.delim)] = tag_buffer;
  }
target_container.push(this->temp_target);
}

template <
  typename charT
, typename traits
, typename allocator
, typename tag_allocator
, typename flag_allocator
, typename targetContainer
>
template <typename targetT>
void
database<charT,traits,allocator,tag_allocator,flag_allocator
,targetContainer>
::next_target(
  targetT const & _target
){
auto & target_container
  = typesystems::use_typebuffer<basic_target<charT,traits,allocator> >
  (this->typesys);
this->next_target();
this->temp_target = target_container.next();
    if (same_target(this->temp_target, _target)){
    target_container.push(this->temp_target);
    return;
    } else {
    this->buffer.push_back(this->temp_target);
    }
/* search previous unused targets for a match. */
auto iter (begin(this->buffer)), iend(end(this->buffer)); 
while (iter != iend){
  if (same_target(*iter, _target)){
  target_container.push(*iter);
  this->buffer.erase(iter);
  return;
  }
}
}

} /* forma */
#endif
