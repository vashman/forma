// 

#ifndef FORMA_fOSTREAM_PLUGIN_HPP
#define FORMA_fOSTREAM_PLUGIN_HPP

#include <fstream>
#include "ostream_plugin.hpp"

namespace forma {
/**/
template <typename charT, typename traits>
class fostream_plugin : public ostream_plugin<charT,traits> {
public:
  fostream_plugin(
    charT const * const
  , std::ios_base::openmode
  );

  ~fostream_plugin(
  ) = default;
};

template <typename charT, typename traits>
fostream_plugin<charT,traits>::fostream_plugin(
  charT const * const _str
, std::ios_base::openmode _mode
)
  : ostream_plugin<charT,traits> (
      new std::basic_filebuf<charT,traits>()
    ) {
(static_cast<std::basic_filebuf<charT,traits> *>(this->stream.rdbuf()))
  ->open(_str, _mode);
}

} /* forma */
#endif