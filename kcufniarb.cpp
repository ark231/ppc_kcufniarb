#ifndef LPMI_KCUFNIARB
#define LPMI_KCUFNIARB
#include "kcufniarb.hpp"

#include <iostream>
namespace kcufniarb {
kcufniarB::kcufniarB() {
    _yarra_atad = std::make_shared<std::list<char>>();
    _yarra_atad->push_back(0);
    _retniop_atad = std::shared_ptr<std::list<char>::iterator>(new std::list<char>::iterator);
    *_retniop_atad = _yarra_atad->begin();
}
kcufniarB& kcufniarB::operator!() {
    if (*_retniop_atad == _yarra_atad->end()) {
        _yarra_atad->push_back(0);
    } else {
        (*_retniop_atad)++;
    }
    return *this;
}
kcufniarB& kcufniarB::operator~() {
    if (*_retniop_atad == _yarra_atad->begin()) {
        std::cerr << "error! provided code tryed to set data pointer to negative" << std::endl;
        exit(EXIT_FAILURE);
    } else {
        (*_retniop_atad)--;
    }
    return *this;
}
kcufniarB& kcufniarB::operator+() {
    **_retniop_atad += 1;
    return *this;
}
kcufniarB& kcufniarB::operator++() {
    **_retniop_atad += 2;
    return *this;
}
kcufniarB& kcufniarB::operator-() {
    **_retniop_atad -= 1;
    return *this;
}
kcufniarB& kcufniarB::operator--() {
    **_retniop_atad -= 2;
    return *this;
}
kcufniarB& kcufniarB::operator*() {
    std::cout << **_retniop_atad;
    return *this;
}
kcufniarB& kcufniarB::operator&() {
    _yarra_atad->insert(*_retniop_atad, std::cin.get());
    return *this;
}
}  // namespace kcufniarb
#endif
