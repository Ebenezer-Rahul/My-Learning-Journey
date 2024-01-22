#pragma once


template<typename T>
class unq_ptr {

private :
    T* m_ptr;

public:

    unq_ptr(T*);

    ~unq_ptr();

    unq_ptr(const unq_ptr<T>& ) = delete;

    unq_ptr(unq_ptr<T>&&);

    unq_ptr<T>& operator= (const unq_ptr<T>&) = delete;

    unq_ptr<T>& operator=(unq_ptr<T>);

    void swap(unq_ptr<T>&);

    T* operator->();

    T& operator*();

};