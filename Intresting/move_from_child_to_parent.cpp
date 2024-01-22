#include <bits/stdc++.h>

class Parent {
private:
    
public:
    std::string m_p;
    Parent() 
    : m_p ("Parent")
    {
    }
   
    virtual void print() {
        std::cout <<" Calling Parent::print" << std::endl;
        std::cout << "m_p :" << m_p << std::endl;
    };
};

class Child : public Parent {

public :

    std::string m_c;
    Child()
    : Parent()
    , m_c("Child")
    {
    }
    void print() {
        std::cout << "calling Child::child"<< std::endl;
        std::cout << "m_p :" <<m_p << " " <<"m_c :" << m_c << std::endl;
    }

};

int main() {
    std::vector<Parent> arr;

    Child c;
    Parent p;
    Parent p1 {std::move(c)};
    p.print();
    p1.print();
    c.print();

    return 0;
}

/*
Output

Calling Parent::print
m_p :Parent
 Calling Parent::print
m_p :Parent
calling Child::child
m_p : m_c :Child


Here only parent_portion was moved 

I think compiler should have warned 

*/