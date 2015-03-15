// inputs the build template

//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef FORMA_ISTREAM_PLUGIN_HPP
#define FORMA_ISTREAM_PLUGIN_HPP

namespace forma {

class istream_plugin {
public:
  virtual
  ~istream_plugin();

  std::basic_istream<char_t, traits_t> stream;
};

} /* forma */
#endif
