//

//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef FORMA_FORMA_TCC
#define FORMA_FORMA_TCC

namespace forma {
/**/
template <
  typename InputIter
, typename FwdIter
>
bool
validate_target(
  InputIter _begin
, InputIter _end
, FwdIter _begin2
, FwdIter _end2
){
  if (_begin == _end) return true;
return (
  tag_end
!=
  find_first_of(
    _begin
  , _end
  , _begin2
  , _end2
  )
);
}

/* used to hold generated output */
string_t buffer; 
const int buffer_size = 127;
char_t iobuffer[buffer_size];
 /* end of entire buffer */
auto buffend (end(iobuffer))
   , buffbegin (begin(iobuffer))
/* current read position in buffer */
   , buffiter (begin(iobuffer)); 

bool statement_begin = false
   , statement_middle = false;
 
/* read through stream */
while (build_template.read(
         iobuffer
      , buffer_size)
){
  if (statement_begin == false){
  buffiter
    = find(
        buffbegin
      , buffend
      , head.delim
      );
  build_file.stream.write(
    *buffbegin
  , std::distance(buffbegin, buffiter)
  );
    if (buffiter == buffend) continue;
  statement_begin = true;
  }
  if (statement_middle == false){
  buffer.append(buffiter, buffend);
  auto iend = cend(buffer);
  auto iter
     = find(
         begin(buffer)
       , iend
       , head.delim
       );
    if (statement_middle
          = (iter == iend)
    ) continue;
  tag.assign(iter, iend);
  buffer.erase(iter, iend);
  }
/* This assumes the next char after
buffmid is a tag cheack delimator.
*/
auto tag_iter
  = find_tag(
      next(buffmid)
    , buffend
    , head.in
    , head.ex
    );
/* Check the next tag can not be found. 
*/
  while (tag_iter != buffend) { 
    if (!validate_tag(*buffmid
                   , listbegin
                   , listend
                   , head.in
                   , head.ex
                   , tag_compare())
    ){ /* tag did not validate */
    buffmid = buffend;
    statement_begin = buffend;
    tag_iter = buffend;
    continue;
    }
  tag_iter
    = find_tag(
        next(buffmid)
      , buffend
      , head.in
      , head.ex
      );
  }
  if ((buffiter
        = find(
            tag_iter
          , buffend
          , head.delim
          )
      )
     !=
     buffend
  ){
  break;
  }

/* lookup tag and replace value */
build_file.stream
  << *(find_replacement(
        taglist_begin
      , taglist_end
      , default_subtag
      , tag
      ));
}

}/* forma */
#endif
