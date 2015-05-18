//

#ifndef FORMA_fISTREAM_PLUGIN_HPP
#define FORMA_fISTREAM_PLUGIN_HPP

#include <fstream>
#include "istream_plugin.hpp"

namespace forma {
/**/
template <typename charT, typename traits>
class fistream_plugin : public istream_plugin<charT,traits> {
public:
  fistream_plugin(
    charT const * const
  , std::ios_base::openmode
  );

  ~fistream_plugin(
  ) = default;
};

template <typename charT, typename traits>
fistream_plugin<charT,traits>::fistream_plugin(
  charT const * const _str
, std::ios_base::openmode _mode
)
  : istream_plugin<charT,traits> (
      new std::basic_filebuf<charT,traits>()
    ) {
(static_cast<std::basic_filebuf<charT,traits> *>(this->stream.rdbuf()))
  ->open(_str, _mode);
}

} /* forma */
#endif