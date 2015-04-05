// outputs the build script

#ifndef FORMA_OSTREAM_PLUGIN_HPP
#define FORMA_OSTREAM_PLUGIN_HPP

#include <ostream>

namespace forma {
/**/
template <typename charT, typename traits>
class ostream_plugin {
public:
  /* ctor */
  ostream_plugin(
    std::basic_streambuf<charT,traits> *
  );

  virtual
  ~ostream_plugin(
  ) = default;

  std::basic_ostream<charT,traits> stream;
};

template <typename charT, typename traits>
ostream_plugin<charT,traits>::ostream_plugin(
  std::basic_streambuf<charT,traits> * _buf
)
  : stream (_buf) {
}

} /* forma */
#endif