#pragma once
#include <bits/stdc++.h>
#include "shared_ptr.hpp"

namespace verd {

template<typename T> 
class weak_ptr {
private: 
    T* m_ptr {nullptr};
    control_block *m_cb {nullptr};

public :
    weak_ptr() 
    : m_ptr(nullptr)
    , m_cb(nullptr)
    {
    }

    ~weak_ptr() {
        if(!m_cb)
            return;
        --(m_cb->watch); 
        if(m_cb->watch == 0) {
            delete m_cb;
            m_cb = nullptr;
        }
    }

    weak_ptr(const weak_ptr<T>& weak_ptr) = delete;
    weak_ptr(weak_ptr<T>& weak_ptr) = delete;

    weak_ptr(const shared_ptr<T>& sh_ptr) {
        if(! sh_ptr.m_cb)
            return ;
        m_ptr = sh_ptr.m_ptr;
        m_cb = sh_ptr.m_cb;
        ++(m_cb->watch);
    }

    weak_ptr(shared_ptr<T> &&sh_ptr) = delete;

    weak_ptr<T>& operator=(weak_ptr<T> temp) {
        temp.swap(*this);
        return *this;
    } 

    void swap(weak_ptr<T> &sh_ptr) {
        std::swap(m_ptr, sh_ptr.m_ptr);
        std::swap(m_cb, sh_ptr.m_cb);
    }

    T& operator* () {
        if(!(m_cb->own))
            std::cout << "owner dead" << std::endl;
        return *m_ptr;
    }

    T* operator-> () {
        if(!(m_cb->own))
            std::cout << "owner dead" << std::endl;
        return m_ptr;
    }
};

}