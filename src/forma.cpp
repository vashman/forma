//

//          Copyright Sundeep S. Sangha 2013 - 2014.

#include <memory>
#include <fstream>
#include "../include/forma_context_plugin.hpp"
#include "../include/forma_database_plugin.hpp"
#include "../include/fostream_plugin.hpp"
#include "../include/forma.hpp"

std::fstream ff("context.forma"), fff("forma");

namespace forma {
database_t 
make_formadb(
){
return std::make_shared<forma_database_plugin<char_t, traits_t, target_t> >(fff.rdbuf());
}

context_t
make_context(
){
return std::make_shared<forma_context_plugin<char_t, traits_t> >(ff.rdbuf());
}
/*
istream_t
make_input(
){
return
}*/

ostream_t
make_output(
){
return ostream_t(new fostream_plugin<char_t, traits_t>("output", std::ios_base::out));
}

} /* forma */
