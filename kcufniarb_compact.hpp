// clang-format off
#if __cplusplus < 201703L
#error "evoba ro 71++c seriuqer yrarbil siht"
#endif
#include<chrono>
#include<climits>
#include<cstdint>
#include<deque>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<list>
#include<stack>
#include<thread>
#include<variant>
#include<vector>
#define X return
#define Y else
#define Z operator
#if defined(BRAINFUCK_CPP_CELL_BITWIDTH) && defined(BRAINFUCK_CPP_CELL_IS_SIGNED)
#define CA BRAINFUCK_CPP_CELL_IS_SIGNED,BRAINFUCK_CPP_CELL_BITWIDTH
#else
#define CA
#endif
namespace{constexpr bool EC=
#ifdef ENABLE_PRINT_CODE
true
#else
false
#endif
;constexpr bool EM=
#ifdef ENABLE_PRINT_CODE
true
#else
false
#endif
;constexpr auto ST=
#ifdef BRAINFUCK_CPP_STEP_SLEEP_TIME
BRAINFUCK_CPP_STEP_SLEEP_TIME
#else
100
#endif
;}
namespace brainfuck{namespace A{struct B{};template <bool a=false,int b=CHAR_BIT>struct C{using D=std::uint8_t;};template <>struct C<true,8>{using D=std::int8_t;};template <>struct C<false,8>{using D=std::uint8_t;};template <>struct C<true,16>{using D=std::int16_t;};template <>struct C<false,16>{using D=std::uint16_t;};template <>struct C<true,32>{using D=std::int32_t;};template <>struct C<false,32>{using D=std::uint32_t;};class E{C<CA>::D G=0;public:using F=decltype(G);E(F a):G(a){}inline Z F(){X G;}inline E&Z+=(F a){G+=a;X*this;}inline E&Z-=(F a){G-=a;X*this;}};}namespace{inline void H(const char*a){if constexpr(EC){std::cerr<<a<<std::flush;}}inline void I(const char*a,std::list<A::E>&b,std::list<A::E>::iterator&c){if constexpr(EM){static bool d=true;if(d){std::cerr<<"\n\n\e[1F\e[1F";d=false;}std::cerr<<"\e[1G\e[2K"<<a<<"\e[1E\e[1G";for(auto&e:b){std::cerr<<std::hex<<std::setw(sizeof(A::E::F)*2)<<std::setfill('0')<<e<<" ";}std::cerr<<"\e[1E\e[2K";if(c==b.end()){std::cerr<<"\nerror: invalid data pointer";exit(EXIT_FAILURE);}for(auto i=0;i<std::distance(b.begin(),c);i++){std::cerr<<std::string(sizeof(A::E::F)*2+1,' ');}std::cerr<<std::string(sizeof(A::E::F),' ')<<"^\e[1F\e[1F";std::cerr<<std::flush;std::this_thread::sleep_for(std::chrono::milliseconds(ST));}}}class Brainfuck{inline static std::list<A::E>J;inline static std::list<A::E>::iterator K;inline static std::size_t L=0;std::deque<std::variant<char,Brainfuck>>M;bool N=false,O=false,P=false,Q=false;void Z()()const{for(auto&&a:M){if(std::holds_alternative<char>(a)){switch(std::get<char>(a)){case'!':!Brainfuck(A::B());break;case'~':~Brainfuck(A::B());break;case'+':+Brainfuck(A::B());break;case'-':-Brainfuck(A::B());break;case'*':*Brainfuck(A::B());break;case'&':&Brainfuck(A::B());break;default:break;}}Y{while(*K!=0){std::get<Brainfuck>(a)();}}}}Brainfuck(A::B){N=O=false;}public:Brainfuck(){if(L==0){J=std::list<A::E>();J.push_back(0);K=J.begin();N=!(P=O=true);L++;}Y{O=!(N=true);L++;}}~Brainfuck(){if(O){L=0;}}Brainfuck&Z!(){if(N){M.push_back('!');}Y{if(static_cast<size_t>(std::distance(J.begin(),K))==std::size(J)-1){J.push_back(0);K++;}Y{K++;}H(">");I(">",J,K);}X*this;}Brainfuck&Z~(){if(N){M.push_back('~');}Y{if(K==J.begin()){std::cerr<<"error! provided code tryed to set data pointer to negative"<<std::endl;exit(EXIT_FAILURE);}Y{K--;}H("<");I("<",J,K);}X*this;}Brainfuck&Z+(){if(N){M.push_back('+');}Y{*K+=1;H("+");I("+",J,K);}X*this;}Brainfuck&Z++(){if(N){M.push_back('+');M.push_back('+');}Y{*K+=2;H("+");H("+");I("++",J,K);}X*this;}Brainfuck&Z-(){if(N){M.push_back('-');}Y{*K-=1;H("-");I("-",J,K);}X*this;}Brainfuck&Z--(){if(N){M.push_back('-');M.push_back('-');}Y{*K-=2;H("-");H("-");I("--",J,K);}X*this;}Brainfuck&Z*(){if(N){M.push_back('*');}Y{std::cout<<static_cast<char>(*K)<<std::flush;H(".");I(".",J,K);}X*this;}Brainfuck&Z&(){if(N){M.push_back('&');}Y{J.insert(K,std::cin.get());H(",");I(",",J,K);}X*this;}Brainfuck Z[](const Brainfuck&a){if(!this->N){X*this;}Y{this->M.push_back(a);this->Q=true;X*this;}}Brainfuck Z|=(const Brainfuck&a){if(a.P){if(*K!=0){(*this)();}Brainfuck b;b.P=b.N=true;X b;}Y if(a.Q){this->M.push_front(a);X*this;}Y{auto c=a.M;for(auto&operation:this->M){c.push_back(operation);}std::swap(this->M,c);X*this;}}};}
#if defined(GNISU_BRAINFUCK_CPP) || defined(BRAINFUCK_CPP_ENABLE_USING)
using brainfuck::_;using brainfuck::Brainfuck;
#elif defined(BRAINFUCK_CPP_ENABLE_MACRO)
#define _ brainfuck::Brainfuck()
#endif
#undef X
#undef Y
#undef Z
#undef CA
// clang-format on
