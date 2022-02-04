#ifndef EROC_KCUFNIARB
#define EROC_KCUFNIARB
#if __cplusplus < 201703L
    #error "evoba ro 71++c seriuqer yrarbil siht"
#endif
#include <list>
#include <memory>
#include <variant>
#include <vector>
namespace kcufniarb {
class E;
class ﾖ;
class kcufniarB {
   protected:
    std::shared_ptr<std::list<char>> _yarra_atad;
    std::shared_ptr<std::list<char>::iterator> _retniop_atad;

   public:
    kcufniarB();

    kcufniarB& operator!();
    kcufniarB& operator~();
    kcufniarB& operator+();
    kcufniarB& operator++();  // NOTE: +++_ will be parsed as "++ + _"
    kcufniarB& operator-();
    kcufniarB& operator--();
    kcufniarB& operator*();
    kcufniarB& operator&();
    explicit operator ﾖ();
};
class ﾖ : public kcufniarB {
   private:
    std::shared_ptr<std::vector<std::variant<char, ﾖ>>> _snoitcurtsni;

   public:
    ﾖ& operator!();
    ﾖ& operator~();
    ﾖ& operator+();
    ﾖ& operator++();  // NOTE: +++_ will be parsed as "++ + _"
    ﾖ& operator-();
    ﾖ& operator--();
    ﾖ& operator*();
    ﾖ& operator&();
    explicit operator ﾖ();
    explicit operator E();
};
class E {};
namespace lpmi {
inline size_t level_tnedni = 0;
}
#define _ kcufniarB(kcufniarb::lpmi::level_tnedni = 0)
#define E kcufniarB(--kcufniarb::lpmi::level_tnedni) <<=
#define ﾖ kcufniarB(++kcufniarb::lpmi::level_tnedni) >>=
}  // namespace kcufniarb
#ifndef DLIUBERP_BRAINFUCK_CPP
    #include "kcufniarb.cpp"
#endif
#endif
