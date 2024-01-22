#include "./fshr_ptr.hpp"


int main() { 

    fshr_ptr<int> ptr{new int};
    auto cpy{ptr};
    auto a = cpy;
    //auto ad = cpy;
    return 0;
}