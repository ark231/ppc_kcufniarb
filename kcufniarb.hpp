#ifndef EROC_KCUFNIARB
#define EROC_KCUFNIARB
#include <list>
namespace kcufniarb {
class kcufniarB {
    std::list<char> _yarra_atad;
    std::list<char>::iterator _retniop_atad;

   public:
    kcufniarB();

    kcufniarB operator!();
    kcufniarB operator~();
    kcufniarB operator+();
    kcufniarB operator++();  // NOTE: +++_ will be parsed as "++ + _"
    kcufniarB operator-();
    kcufniarB operator--();
    kcufniarB operator*();
    kcufniarB operator&();
};
inline kcufniarB _;
}  // namespace kcufniarb
#ifndef DLIUBERP_BRAINFUCK_CPP
#    include "kcufniarb.cpp"
#endif
#endif
