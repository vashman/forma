class tag_iwriter
  : public typesystems
::iwriter<taxo::tag> {
public:
  typedef typename typesystems
  ::iwriter<taxo::tag>::value_type
  value_type;

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

void
tag_iwriter::do_get(
   value_type & _value
,   typesystems
  ::typebuffer_container const & _buffer
,   typesystems
  ::iwriter_container const & _writer
) const {
std::string str;
  typesystems
::rewrite(str, _buffer, _writer);
_value = taxo::tag(str.c_str());
}

bool
tag_iwriter::do_empty(
    typesystems
  ::typebuffer_container const & _buffer
,   typesystems
  ::iwriter_container const & _writer
) const {
return false;
}

namespace taxo {
data_pattern::data_model &
operator>>(
  data_pattern::data_model &
, taxo::tag &
);

data_pattern::data_model &
operator>>(
  data_pattern::data_model & _dm
, taxo::tag & _tag
){
data_pattern::rewrite(_dm, _tag);
return _dm;
}
}
