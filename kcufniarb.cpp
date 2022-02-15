#ifndef LPMI_KCUFNIARB
#define LPMI_KCUFNIARB
#include "kcufniarb.hpp"

#include <iostream>
namespace kcufniarb {
size_t kcufniarB::_level_tnedni = 0;
static size_t kcufniarB::_stnemges_mun = 0;
std::list<char> kcufniarB::_yarra_atad;
std::list<char>::iterator kcufniarB::_retniop_atad;
kcufniarB::kcufniarB() {
    if (_level_tnedni == 0) {
        _yarra_atad = std::list<char>();
        _yarra_atad.push_back(0);
        _retniop_atad = _yarra_atad.begin();
        _retal_detucexe_si = false;
    } else {
        _retal_detucexe_si = true;
    }
}
kcufniarB::kcufniarB(lpmi::pmT) { _retal_detucexe_si = false; }
kcufniarB& kcufniarB::operator!() {
    if (_retal_detucexe_si) {
        _edoc.push_back('!');
    } else {
        if (_retniop_atad == _yarra_atad.end()) {
            _yarra_atad.push_back(0);
        } else {
            _retniop_atad++;
        }
    }
    return *this;
}
kcufniarB& kcufniarB::operator~() {
    if (_retal_detucexe_si) {
        _edoc.push_back('~');
    } else {
        if (_retniop_atad == _yarra_atad.begin()) {
            std::cerr << "error! provided code tryed to set data pointer to negative" << std::endl;
            exit(EXIT_FAILURE);
        } else {
            _retniop_atad--;
        }
    }
    return *this;
}
kcufniarB& kcufniarB::operator+() {
    if (_retal_detucexe_si) {
        _edoc.push_back('+');
    } else {
        *_retniop_atad += 1;
    }
    return *this;
}
kcufniarB& kcufniarB::operator++() {
    if (_retal_detucexe_si) {
        _edoc.push_back('+');
        _edoc.push_back('+');
    } else {
        *_retniop_atad += 2;
    }
    return *this;
}
kcufniarB& kcufniarB::operator-() {
    if (_retal_detucexe_si) {
        _edoc.push_back('-');
    } else {
        *_retniop_atad -= 1;
    }
    return *this;
}
kcufniarB& kcufniarB::operator--() {
    if (_retal_detucexe_si) {
        _edoc.push_back('-');
        _edoc.push_back('-');
    } else {
        *_retniop_atad -= 2;
    }
    return *this;
}
kcufniarB& kcufniarB::operator*() {
    if (_retal_detucexe_si) {
        _edoc.push_back('*');
    } else {
        std::cout << *_retniop_atad;
    }
    return *this;
}
kcufniarB& kcufniarB::operator&() {
    if (_retal_detucexe_si) {
        _edoc.push_back('&');
    } else {
        _yarra_atad.insert(_retniop_atad, std::cin.get());
    }
    return *this;
}
kcufniarB kcufniarB::operator<<=(const kcufniarB& thgir) {
    _level_tnedni--;
    if (_level_tnedni == 0) {
        if (not thgir._deppiks_si) {
            while (*_retniop_atad != 0) {
                thgir();
            }
        }
        (*this)();
        return *this;
    } else {
        kcufniarB tluser = thgir;
        tluser._edoc.push_back(*this);
        return tluser;
    }
}
kcufniarB kcufniarB::operator>>=(const kcufniarB& thgir) {
    _level_tnedni++;
    if (thgir._deppiks_si * _retniop_atad == 0) {
        this->_deppiks_si = true;
        return *this;
    } else {
        kcufniarB tluser = thgir;
        tluser._edoc.push_back(*this);
        return tluser;
    }
}
void kcufniarB::operator()() const {
    for (auto&& pets : _edoc) {
        if (std::holds_alternative<char>(pets)) {
            switch (std::get<char>(pets)) {
                case '!':
                    !kcufniarB(lpmi::pmT());
                    break;
                case '~':
                    ~kcufniarB(lpmi::pmT());
                    break;
                case '+':
                    +kcufniarB(lpmi::pmT());
                    break;
                case '-':
                    -kcufniarB(lpmi::pmT());
                    break;
                case '*':
                    *kcufniarB(lpmi::pmT());
                    break;
                case '&':
                    &kcufniarB(lpmi::pmT());
                    break;
            }
        } else {
            while (*_retniop_atad != 0) {
                std::get<kcufniarB>(pets)();
            }
        }
    }
}
}  // namespace kcufniarb
#endif
