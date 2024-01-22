#include "./unq_ptr.hpp"
#include <bits/stdc++.h>

template<typename T>
unq_ptr<T>::unq_ptr(T* ptr) {
    m_ptr = ptr;
}

template<typename T>
unq_ptr<T>::~unq_ptr() {
    delete m_ptr;
}

template<typename T>
unq_ptr<T>::unq_ptr(unq_ptr<T>&& prev) {
    m_ptr = prev.m_ptr;
    prev.m_ptr = nullptr;
}

template<typename T>
unq_ptr<T>& unq_ptr<T>::operator=(unq_ptr<T> prev) {
    prev.swap(*this);
    return *this;
}

template<typename T> 
void unq_ptr<T>::swap(unq_ptr<T>& a) {
    std::swap(a.m_ptr, m_ptr);
}

template<typename T> 
T* unq_ptr<T>::operator->() {
    return m_ptr;
}

template<typename T> 
T& unq_ptr<T>::operator*() {
    return *m_ptr;
}


int main() { 
    int a = 0;
    unq_ptr<int> ptr{new int};
    auto cpy{std::move(ptr)};
    auto ad = std::move(cpy);
    return 0;
}