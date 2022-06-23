#ifndef EROC_KCUFNIARB
#define EROC_KCUFNIARB
#if __cplusplus < 201703L
    #error "evoba ro 71++c seriuqer yrarbil siht"
#endif
#include <climits>
#include <cstdint>
#include <deque>
#include <list>
#include <stack>
#include <variant>
#include <vector>
namespace brainfuck {
namespace impl {
struct Tmp {};

template <bool is_signed = false, int bitwidth = CHAR_BIT>
struct Integer {
    using type = std::uint8_t;
};
template <>
struct Integer<true, 8> {
    using type = std::int8_t;
};
template <>
struct Integer<false, 8> {
    using type = std::uint8_t;
};
template <>
struct Integer<true, 16> {
    using type = std::int16_t;
};
template <>
struct Integer<false, 16> {
    using type = std::uint16_t;
};
template <>
struct Integer<true, 32> {
    using type = std::int32_t;
};
template <>
struct Integer<false, 32> {
    using type = std::uint32_t;
};
class CellType {
#if defined(BRAINFUCK_CPP_CELL_BITWIDTH) && defined(BRAINFUCK_CPP_CELL_IS_SIGNED)
    Integer<BRAINFUCK_CPP_CELL_IS_SIGNED, BRAINFUCK_CPP_CELL_BITWIDTH>::type value_ = 0;
#else
    Integer<>::type value_ = 0;
#endif
   public:
    using value_type = decltype(value_);
    CellType(value_type value) : value_(value) {}
    inline operator value_type() { return value_; }
    inline CellType& operator+=(value_type inc) {
        value_ += inc;
        return *this;
    }
    inline CellType& operator-=(value_type inc) {
        value_ -= inc;
        return *this;
    }
};
}  // namespace impl

class Brainfuck {
   public:
    Brainfuck();
    ~Brainfuck();

    Brainfuck& operator!();
    Brainfuck& operator~();
    Brainfuck& operator+();
    Brainfuck& operator++();  // NOTE: +++_ will be parsed as "++ + _"
    Brainfuck& operator-();
    Brainfuck& operator--();
    Brainfuck& operator*();
    Brainfuck& operator&();

    Brainfuck operator[](const Brainfuck&);
    Brainfuck operator|=(const Brainfuck&);

   private:
    inline static std::list<impl::CellType> data_array_;
    inline static std::list<impl::CellType>::iterator data_pointer_;
    inline static std::size_t num_segments_ = 0;

    std::deque<std::variant<char, Brainfuck>> code_;
    bool is_executed_later_ = false;
    bool is_first_ = false;
    bool is_toplevel_ = false;
    bool is_loop_ = false;

    void operator()() const;
    Brainfuck(impl::Tmp);
};
using _ = Brainfuck;
}  // namespace brainfuck

#if defined(GNISU_BRAINFUCK_CPP) || defined(BRAINFUCK_CPP_ENABLE_USING)
using brainfuck::_;
using brainfuck::Brainfuck;
#elif defined(BRAINFUCK_CPP_ENABLE_MACRO)
    #define _ brainfuck::Brainfuck()
#endif
#endif
