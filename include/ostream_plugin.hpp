// outputs the build script

#ifndef FORMA_OSTREAM_PLUGIN_HPP
#define FORMA_OSTREAM_PLUGIN_HPP

#include <ostream>

namespace forma {
/**/
template <
  typename charT
, typename traits
>
class ostream_plugin
 : public 
    std::basic_ostream<charT,traits> {
public:
  /* ctor */
  ostream_plugin(
    std::basic_streambuf<charT,traits> *
  );

  virtual
  ~ostream_plugin(
  ) = default;

};

template <
  typename charT
, typename traits
>
ostream_plugin<charT,traits>
::ostream_plugin(
  std::basic_streambuf<charT,traits>
    * _buf
)
  : std::basic_ostream<charT,traits>
     (_buf) {
}

} /* forma */
#endif