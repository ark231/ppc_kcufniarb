#ifndef LPMI_KCUFNIARB
#define LPMI_KCUFNIARB
#include "kcufniarb.hpp"

#include <chrono>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <thread>

namespace brainfuck {
namespace {
inline void print_code(const char* code) {
#ifdef ENABLE_CODE_PRINT
    std::cerr << code << std::flush;
#endif
}
inline void print_memory(const char* code, std::list<impl::CellType>& data_array,
                         std::list<impl::CellType>::iterator& data_pointer) {
#ifdef ENABLE_PRINT_MEMORY
    static bool is_first = true;
    if (is_first) {
        std::cerr << "\n\n";
        std::cerr << "\e[1F";
        std::cerr << "\e[1F";
        is_first = false;
    }
    std::cerr << "\e[1G";
    std::cerr << "\e[2K";
    std::cerr << code;
    std::cerr << "\e[1E";
    std::cerr << "\e[1G";
    for (auto& datum : data_array) {
        std::cerr << std::hex << std::setw(sizeof(impl::CellType::value_type) * 2) << std::setfill('0') << datum;
        std::cerr << " ";
    }
    std::cerr << "\e[1E";
    std::cerr << "\e[2K";
    if (data_pointer == data_array.end()) {
        std::cerr << "\n";
        std::cerr << "error: invalid data pointer";
        exit(EXIT_FAILURE);
    }
    for (auto i = 0; i < std::distance(data_array.begin(), data_pointer); i++) {
        std::cerr << std::string(sizeof(impl::CellType::value_type) * 2, ' ');
    }
    std::cerr << std::string(sizeof(impl::CellType::value_type), ' ') << "^";
    std::cerr << "\e[1F";
    std::cerr << "\e[1F";
    std::cerr << std::flush;
    #ifdef BRAINFUCK_CPP_STEP_SLEEP_TIME
    std::this_thread::sleep_for(std::chrono::milliseconds(BRAINFUCK_CPP_STEP_SLEEP_TIME));
    #else
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    #endif
#endif
}
}  // namespace
Brainfuck::Brainfuck() {
    if (num_segments_ == 0) {
        data_array_ = std::list<impl::CellType>();
        data_array_.push_back(0);
        data_pointer_ = data_array_.begin();
        is_executed_later_ = false;
        is_toplevel_ = true;
        is_first_ = true;
        num_segments_++;
        // dprint("fitst");
    } else {
        is_executed_later_ = true;
        is_first_ = false;
        num_segments_++;
        // dprint("not fitst");
    }
}
Brainfuck::Brainfuck(impl::Tmp) {
    is_executed_later_ = false;
    is_first_ = false;
}
Brainfuck::~Brainfuck() {
    if (is_first_) {
        //リセット
        // dprint("reset");
        num_segments_ = 0;
    }
}
Brainfuck& Brainfuck::operator!() {
    //    std::cout << __PRETTY_FUNCTION__ << std::endl;
    if (is_executed_later_) {
        code_.push_back('!');
    } else {
        if (static_cast<size_t>(std::distance(data_array_.begin(), data_pointer_)) == std::size(data_array_) - 1) {
            data_array_.push_back(0);
            data_pointer_++;
        } else {
            data_pointer_++;
        }
        print_code(">");
        print_memory(">", data_array_, data_pointer_);
    }
    return *this;
}
Brainfuck& Brainfuck::operator~() {
    //    std::cout << __PRETTY_FUNCTION__ << std::endl;
    if (is_executed_later_) {
        code_.push_back('~');
    } else {
        if (data_pointer_ == data_array_.begin()) {
            std::cerr << "error! provided code tryed to set data pointer to negative" << std::endl;
            exit(EXIT_FAILURE);
        } else {
            data_pointer_--;
        }
        print_code("<");
        print_memory("<", data_array_, data_pointer_);
    }
    return *this;
}
Brainfuck& Brainfuck::operator+() {
    //    std::cout << __PRETTY_FUNCTION__ << std::endl;
    if (is_executed_later_) {
        code_.push_back('+');
    } else {
        *data_pointer_ += 1;
        print_code("+");
        print_memory("+", data_array_, data_pointer_);
    }
    return *this;
}
Brainfuck& Brainfuck::operator++() {
    //    std::cout << __PRETTY_FUNCTION__ << std::endl;
    if (is_executed_later_) {
        code_.push_back('+');
        code_.push_back('+');
    } else {
        *data_pointer_ += 2;
        print_code("+");
        print_code("+");
        print_memory("++", data_array_, data_pointer_);
    }
    return *this;
}
Brainfuck& Brainfuck::operator-() {
    //    std::cout << __PRETTY_FUNCTION__ << std::endl;
    if (is_executed_later_) {
        code_.push_back('-');
    } else {
        *data_pointer_ -= 1;
        print_code("-");
        print_memory("-", data_array_, data_pointer_);
    }
    return *this;
}
Brainfuck& Brainfuck::operator--() {
    //    std::cout << __PRETTY_FUNCTION__ << std::endl;
    if (is_executed_later_) {
        code_.push_back('-');
        code_.push_back('-');
    } else {
        *data_pointer_ -= 2;
        print_code("-");
        print_code("-");
        print_memory("--", data_array_, data_pointer_);
    }
    return *this;
}
Brainfuck& Brainfuck::operator*() {
    //    std::cout << __PRETTY_FUNCTION__ << std::endl;
    if (is_executed_later_) {
        code_.push_back('*');
    } else {
        std::cout << static_cast<char>(*data_pointer_) << std::flush;
        print_code(".");
        print_memory(".", data_array_, data_pointer_);
    }
    return *this;
}
Brainfuck& Brainfuck::operator&() {
    //    std::cout << __PRETTY_FUNCTION__ << std::endl;
    if (is_executed_later_) {
        code_.push_back('&');
    } else {
        data_array_.insert(data_pointer_, std::cin.get());
        print_code(",");
        print_memory(",", data_array_, data_pointer_);
    }
    return *this;
}
Brainfuck Brainfuck::operator[](const Brainfuck& inner) {
    //    std::cout << __PRETTY_FUNCTION__ << std::endl;
    if (not this->is_executed_later_) {
        return *this;
    } else {
        this->code_.push_back(inner);
        this->is_loop_ = true;
        return *this;
    }
}
Brainfuck Brainfuck::operator|=(const Brainfuck& right) {
    //    std::cout << __PRETTY_FUNCTION__ << std::endl;
    if (right.is_toplevel_) {
        if (*data_pointer_ != 0) {
            (*this)();
        }
        Brainfuck result;
        result.is_toplevel_ = true;
        result.is_executed_later_ = true;
        return result;
    } else if (right.is_loop_) {  // maybe skipped?
        this->code_.push_front(right);
        return *this;
    } else {
        auto concatenated_code = right.code_;
        for (auto& operation : this->code_) {
            concatenated_code.push_back(operation);
        }
        std::swap(this->code_, concatenated_code);
        return *this;
    }
}
void Brainfuck::operator()() const {
    //    std::cout << __PRETTY_FUNCTION__ << std::endl;
    for (auto&& step : code_) {
        if (std::holds_alternative<char>(step)) {
            switch (std::get<char>(step)) {
                case '!':
                    !Brainfuck(impl::Tmp());
                    break;
                case '~':
                    ~Brainfuck(impl::Tmp());
                    break;
                case '+':
                    +Brainfuck(impl::Tmp());
                    break;
                case '-':
                    -Brainfuck(impl::Tmp());
                    break;
                case '*':
                    *Brainfuck(impl::Tmp());
                    break;
                case '&':
                    &Brainfuck(impl::Tmp());
                    break;
                default:
                    // ignore
                    break;
            }
        } else {
            while (*data_pointer_ != 0) {
                std::get<Brainfuck>(step)();
            }
        }
    }
}
}  // namespace brainfuck
#endif
