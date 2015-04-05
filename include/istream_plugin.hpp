// inputs the build template

//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef FORMA_ISTREAM_PLUGIN_HPP
#define FORMA_ISTREAM_PLUGIN_HPP

#include <istream>

namespace forma {
/**/
template <typename charT, typename traits>
class istream_plugin {
public:
  /* ctor */
  istream_plugin(
    std::basic_streambuf<charT,traits> *
  );
  
  virtual
  ~istream_plugin(
  ) = default;

  std::basic_istream<charT,traits> stream;
};

template <typename charT, typename traits>
istream_plugin<charT,traits>::istream_plugin(
  std::basic_streambuf<charT,traits> * _buf
)
  : stream (_buf) {
}

} /* forma */
#endif