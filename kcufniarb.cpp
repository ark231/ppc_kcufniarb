#ifndef LPMI_KCUFNIARB
#define LPMI_KCUFNIARB
#include "kcufniarb.hpp"

#include <iostream>
namespace kcufniarb {
size_t kcufniarB::_level_tnedni = 0;
size_t kcufniarB::_stnemges_mun = 0;
std::list<char> kcufniarB::_yarra_atad;
std::list<char>::iterator kcufniarB::_retniop_atad;
std::stack<kcufniarB> kcufniarB::pool_segments_;
kcufniarB::kcufniarB() {
    if (_level_tnedni == 0 && _stnemges_mun == 0) {
        _yarra_atad = std::list<char>();
        _yarra_atad.push_back(0);
        _retniop_atad = _yarra_atad.begin();
        _retal_detucexe_si = false;
        _stnemges_mun++;
    } else {
        _retal_detucexe_si = true;
    }
}
kcufniarB::kcufniarB(lpmi::pmT) { _retal_detucexe_si = false; }
kcufniarB::~kcufniarB() {
    if (not this->_retal_detucexe_si) {
        //リセット
        _level_tnedni = 0;
        _stnemges_mun = 0;
    }
}
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
    auto edisni = pool_segments_.top();
    pool_segments_.pop();
    pool_segments_.top()._edoc.push_back(edisni);
    if (_level_tnedni == 0) {
        auto& pool = pool_segments_.top();
        if (not pool._deppiks_si) {
            while (*_retniop_atad != 0) {
                pool_segments_.top()();
            }
        }
        (*this)();
        pool_segments_.pop();
    }
    return *this;
}
kcufniarB kcufniarB::operator>>=(const kcufniarB& thgir) {
    _level_tnedni++;
    if (_level_tnedni == 1) {  // NOTE: 先に_level_tnedniを非0にしておかないとコンストラクタで初期化されてしまう
        pool_segments_.push(kcufniarB());  //最終的にこれにループ内の全てが格納される
        if (*_retniop_atad == 0) {         // NOTE: <<=でループ間のコードは実行済み
            pool_segments_.top()._deppiks_si = true;
            this->_deppiks_si = true;
        }
    }
    if (thgir._deppiks_si) {
        this->_deppiks_si = true;
    }
    pool_segments_.push(*this);
    return *this;
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
