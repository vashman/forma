//

#ifndef FORMA_CONTEXT_DATAMODEL_TCC
#define FORMA_CONTEXT_DATAMODEL_TCC

#include <string>

namespace forma {
/* context_datamodel ctor */
template <
  typename streamT
, typename tagT
, typename flagT
>
template <
  typename tag_container
, typename flag_container
, typename streambufT
>
context_datamodel<streamT, tagT, flagT>
  ::context_datamodel
(
   streambufT _buffer
)
  : stream (_buffer)
  , header (
      get_context_header(this->stream)
  ) {
/* set buffer for tags as
  forma::basic_flag
*/
typesystems::set_typebuffer<
  flagT
, flag_container
>
(this->typesys);
/* set buffer for flags as
  std::basic_tag
*/
typesystems::set_typebuffer<
  tagT
, tag_container
>
(this->typesys);
}

/* context_datamodel dtor */
template <
  typename streamT
, typename tagT
, typename flagT
>
context_datamodel<streamT, tagT, flagT>
  ::~context_datamodel(
){
}

/* context_datamodel get_tags */
template <
  typename streamT
, typename tagT
, typename flagT
>
void
context_datamodel<streamT, tagT, flagT>
  ::get_tags(
){
auto & buff
  = typesystems::use_typebuffer<tag>
  (this->typesys);

  while (
    stream.peek()
  !=
    this->header.section_delim
  ) {
  buff.push(
    get_tag<tagT>(
      this->stream
    , this->header.section_delim
    , this->header.seperator_delim
    )
  );
  }
}

/* context_datamodel get_flags */
template <
  typename streamT
, typename tagT
, typename flagT
>
void
context_datamodel<streamT, tagT, flagT>
  ::get_flags(
){
auto & buff
  = typesystems::use_typebuffer<flagT>
  (this->typesys);

this->stream.get();
  while (
    this->stream.peek()
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
