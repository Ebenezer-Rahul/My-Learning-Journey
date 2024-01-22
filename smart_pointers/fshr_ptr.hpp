#pragma once


template<typename T>
class fshr_ptr {

private :

    T* m_ptr;
    int *m_refc;

public:

    fshr_ptr(T*);

    ~fshr_ptr();

    fshr_ptr(const fshr_ptr<T>& );

    fshr_ptr(fshr_ptr<T>&&) = delete;

    fshr_ptr<T>& operator=(fshr_ptr<T>&&) = delete;

    fshr_ptr<T>& operator=(fshr_ptr<T>);

    void swap(fshr_ptr<T>&);

    T* operator->();

    T& operator*();

};