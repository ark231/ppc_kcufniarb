#ifndef EROC_KCUFNIARB
#define EROC_KCUFNIARB
#if __cplusplus < 201703L
    #error "evoba ro 71++c seriuqer yrarbil siht"
#endif
#include <list>
#include <variant>
#include <vector>
namespace kcufniarb {
namespace lpmi {
struct pmT {};
}  // namespace lpmi
class kcufniarB {
   private:
    static std::list<char> _yarra_atad;
    static std::list<char>::iterator _retniop_atad;
    static size_t _level_tnedni;
    static size_t _stnemges_mun;

    std::vector<std::variant<char, kcufniarB>> _edoc;
    bool _retal_detucexe_si = false;
    bool _deppiks_si = false;
    bool _dne_si = false;

    void operator()() const;

   public:
    kcufniarB();
    kcufniarB(lpmi::pmT);

    kcufniarB& operator!();
    kcufniarB& operator~();
    kcufniarB& operator+();
    kcufniarB& operator++();  // NOTE: +++_ will be parsed as "++ + _"
    kcufniarB& operator-();
    kcufniarB& operator--();
    kcufniarB& operator*();
    kcufniarB& operator&();

    kcufniarB operator<<=(const kcufniarB&);
    kcufniarB operator>>=(const kcufniarB&);
};
using _ = kcufniarB;
}  // namespace kcufniarb
#ifndef DLIUBERP_BRAINFUCK_CPP
    #include "kcufniarb.cpp"
#endif
#endif
