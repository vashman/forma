//

#ifndef FORMA_CONTEXT_DATAMODEL_TCC
#define FORMA_CONTEXT_DATAMODEL_TCC

#include <string>

namespace forma {
/* context_datamodel ctor */
template <
  typename charT
, typename traits
, typename tag_allocator
, typename flag_allocator
>
template <
  typename tag_container
, typename flag_container
>
context_datamodel<
  charT
, traits
, tag_allocator
, flag_allocator
>
  ::context_datamodel
(
  std::basic_streambuf<charT,traits>
    * _buffer
)
  : stream (_buffer)
  , header (
      get_context_header(this->stream)
  ) {
/* set buffer for tags as
forma::basic_flag
*/
typesystems::set_typebuffer<
  basic_flag<
    charT
  , traits
  , flag_allocator
  >
, flag_container>(this->typesys);
/* set buffer for flags as
std::basic_tag
*/
typesystems::set_typebuffer<
  taxo::basic_tag<
    charT
  , traits
  , tag_allocator
  >
, tag_container>(this->typesys);
}

/* context_datamodel dtor */
template <
  typename charT
, typename traits
, typename tag_allocator
, typename flag_allocator
>
context_datamodel<
  charT
, traits
, tag_allocator
, flag_allocator
>
  ::~context_datamodel(
){
}

/* context_datamodel get_tags */
template <
  typename charT
, typename traits
, typename tag_allocator
, typename flag_allocator
>
void
context_datamodel<
  charT
, traits
, tag_allocator
, flag_allocator
>
  ::get_tags(
){
auto & buff
  = typesystems::use_typebuffer<
    basic_tag<
      charT
    , traits
    , tag_allocator
    >
  >(this->typesys);

  while (stream.peek()
        !=
        this->header.section_delim) {
  buff.push(
    get_tag<
      charT
    , traits
    , tag_allocator
    >(
      this->stream
    , this->header.section_delim
    , this->header.seperator_delim
    )
  );
  }
}

/* context_datamodel get_flags */
template <
  typename charT
, typename traits
, typename tag_allocator
, typename flag_allocator
>
void
context_datamodel<
  charT
, traits
, tag_allocator
, flag_allocator
>
  ::get_flags(
){
auto & buff
  = typesystems::use_typebuffer<
      basic_flag<
        charT
      , traits
      , flag_allocator
      >
  >(this->typesys);

this->stream.get();
  while (this->stream.peek()
        !=
        traits::to_int_type(
          this->header.section_delim
         )
  ){
  buff.push(
    get_tag_value<
      charT
    , traits
    , flag_allocator
    >(
      this->stream
    , this->header.section_delim
    , this->header.seperator_delim
    )
  );
  }
}

} /* forma */
#endif
