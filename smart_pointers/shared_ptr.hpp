#pragma once
#include <bits/stdc++.h>
namespace verd {

class control_block {
public : 
    int watch {1};
    int own {1};
    control_block()
    : watch(1)
    , own(1)
    {
    }
};

template<typename T>
class weak_ptr;

template<typename T> 
class shared_ptr {
private: 
    T* m_ptr {nullptr};
    control_block *m_cb {nullptr};

public :
    shared_ptr()
    : m_ptr(nullptr)
    , m_cb(new control_block())
    {
    }

    shared_ptr(T* ptr) {
        m_ptr = ptr;
        m_cb = new control_block();
    }

    ~shared_ptr() {
        --(m_cb->own);
        --(m_cb->watch);
        if(m_cb->own == 0) {
            delete m_ptr;
            m_ptr = nullptr;
        } 
        if(m_cb->watch == 0) {
            delete m_cb;
            m_cb = nullptr;
        }
    }

    shared_ptr(const shared_ptr<T>& sh_ptr) {
        if(! sh_ptr.m_ptr)
            return ;
        m_ptr = sh_ptr.m_ptr;
        m_cb = sh_ptr.m_cb;
        ++(m_cb->own);
        ++(m_cb->watch);
    }

    shared_ptr(shared_ptr<T> &&sh_ptr) = delete;

    shared_ptr<T>& operator=(shared_ptr<T> temp) {
        temp.swap(*this);
        return *this;
    } 

    void swap(shared_ptr<T> &sh_ptr) {
        std::swap(m_ptr, sh_ptr.m_ptr);
        std::swap(m_cb, sh_ptr.m_cb);
    }

    T& operator* () {
        return *m_ptr;
    }

    T* operator-> () {
        return m_ptr;
    }
    friend class weak_ptr<T>;
};

}