// outputs the build script

#ifndef FORMA_OSTREAM_PLUGIN_HPP
#define FORMA_OSTREAM_PLUGIN_HPP

namespace forma {

class stream_plugin {
public:
  virtual
  ~ostream_plugin();

  std::basic_ostream<char_t, traits_t> stream;
};

} /* forma */
#endif
