#include "./fshr_ptr.hpp"
#include <bits/stdc++.h>

template<typename T>
fshr_ptr<T>::fshr_ptr(T* ptr) {
    m_ptr = ptr;
    m_refc = new int {1};
    std::cout << "fshr_ptr created here" << std::endl;
}

template<typename T>
fshr_ptr<T>::~fshr_ptr() {
    --(*m_refc);
    std::cout << "fshr_ptr one out of scope here" << std::endl;
    if(*m_refc == 0){
        delete m_ptr;
        delete m_refc;    
        std::cout << "fshr_ptr destroyed here" << std::endl;
    }
}

template<typename T>
fshr_ptr<T>::fshr_ptr(const fshr_ptr<T>& prev) {
    m_ptr = prev.m_ptr;
    m_refc = prev.m_refc;
    ++(*m_refc);
    std::cout << "fshr_ptr shared here" << std::endl;
}

template<typename T>
fshr_ptr<T>& fshr_ptr<T>::operator=(fshr_ptr<T> prev) {
    prev.swap(*this);
    std::cout << "fshr_ptr shared here" << std::endl;
    return *this;
}

template<typename T> 
void fshr_ptr<T>::swap(fshr_ptr<T>& a) {
    std::swap(a.m_ptr, m_ptr);
    std::swap(a.m_refc, m_refc);
}

template<typename T> 
T* fshr_ptr<T>::operator->() {
    return m_ptr;
}

template<typename T> 
T& fshr_ptr<T>::operator*() {
    return *m_ptr;
}

class Test {
private:
    fshr_ptr<Test> m_buddy;
public: 
    Test() 
    : m_buddy(nullptr) 
    {
        std::cout << "Test obj created";
    }

    void setBuddy(fshr_ptr<Test> &buddy) {
        m_buddy = buddy;
        std::cout << "buddy created" << std::endl;
    }
};

int main() { 
/*
    fshr_ptr<int> ptr{new int};
    auto cpy{ptr};
    auto a = cpy;
    auto ad = cpy;
*/
    fshr_ptr<Test> rahul{new Test ()};
    fshr_ptr<Test> rachana{new Test ()};

    std::cout << "creation completed" <<std::endl; 
    rahul->setBuddy(rachana);
    rachana->setBuddy(rahul);
    std::cout << "buddies set" <<std::endl; 
    std::cout << sizeof(Test) << " " << sizeof(int)<< " " << sizeof(void*) << std::endl;
    return 0;
}