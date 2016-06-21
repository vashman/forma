#include <taxo/relation.hpp>

template <typename T>
class relation_iwriter
  : public typesystems
::iwriter<taxo::relation<T> > {
public:
  typedef typename typesystems
  ::iwriter<taxo::relation<T> >
  ::value_type value_type;

  virtual void
  do_get(
    value_type &
  ,   typesystems
    ::typebuffer_container const &
  ,   typesystems
    ::iwriter_container const &
  ) const;

  virtual bool
  do_empty(
      typesystems
    ::typebuffer_container const &
  ,   typesystems
    ::iwriter_container const &
  ) const;
};

/* do_get */
template <typename T>
void
relation_iwriter<T>::do_get(
   value_type & _value
,   typesystems
  ::typebuffer_container const & _buffer
,   typesystems
  ::iwriter_container const & _writer
) const {
taxo::tag temp_tag;
  typesystems
::rewrite(temp_tag, _buffer, _writer);
T temp;
  typesystems
::rewrite(temp, _buffer, _writer);
_value
= taxo::relation<T>(temp_tag, temp);
}

/* do_empty */
template <typename T>
bool
relation_iwriter<T>::do_empty(
    typesystems
  ::typebuffer_container const & _buffer
,   typesystems
  ::iwriter_container const & _writer
) const {
return false;
}

namespace taxo {
template <typename T>
data_pattern::data_model &
operator>>(
  data_pattern::data_model &
, taxo::relation<T> &
);

template <typename T>
data_pattern::data_model &
operator>>(
  data_pattern::data_model & _dm
, taxo::relation<T> & _relation
){
data_pattern::rewrite(_dm, _relation);
return _dm;
}
}
