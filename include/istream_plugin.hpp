// inputs the build template

//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef FORMA_ISTREAM_PLUGIN_HPP
#define FORMA_ISTREAM_PLUGIN_HPP

namespace forma {
/**/
template <typename istreamT>
class istream_plugin {
public:
  virtual
  ~istream_plugin(
  ) = default;

  istreamT stream;
};

} /* forma */
#endif