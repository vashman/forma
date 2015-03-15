#include <iostream>
#include <sstream>
#include <string>
#include <memory>
#include <stdexcept>
#include "../include/context_datamodel.hpp"
#include "../src/context_plugin.cpp"
#include "../include/forma_context_plugin.hpp"

typedef forma::basic_tag<char, std::char_traits<char>, std::allocator<char> > tag;
typedef forma::basic_flag<char, std::char_traits<char>, std::allocator<char> > flag;

int main() try {
std::string ts(" testing "), tss("01234556789");

std::stringstream ss;
ss << "forma context: # :\n\nTAG:ROOT\nZ:W\n9:8\n\ntag:root:value\nA:B:C\n1:2:3\n\n";
//forma::context_datamodel<char, std::char_traits<char> > db(ss.rdbuf());
std::shared_ptr<forma::context_plugin> db(new forma::forma_context_plugin<char, std::char_traits<char> >(ss.rdbuf()));
db->get_tags();
db->get_flags();

auto itb = std::begin(ts);
auto itbb = std::begin(tss);
tag temp(itb, std::end(ts), itb, std::end(ts));
flag temp_flag(itbb, itbb+2, itbb+4, std::end(tss));

  while (forma::empty<flag>(db) == false){
  db >> temp_flag;
  std::cout << "tag: " << temp_flag.tag.c_str() << "\n  root: " << temp_flag.root.c_str()
      << "\n  vlaue: " << temp_flag.value.c_str() << std::endl;
  }

std::cout << "--------------\n";

  while (forma::empty<tag>(db) == false){
  db >> temp;
  std::cout << "tag: " << temp.tag.c_str() << "\n  root: " << temp.root.c_str() << std::endl;
  }

return 0;
} catch (std::runtime_error const & _e) {
std::cerr << _e.what();
}
