#include <bits/stdc++.h>

class Parent {
private:
    int m_p;
public:

    Parent() 
    : m_p (1)
    {
    }
   
    virtual void print() {
        std::cout << m_p << std::endl;
    };
};

class Child : public Parent {
private : 
    int m_c;
public :
    Child()
    : Parent()
    , m_c(2)
    {
    }
    void print() {
        std::cout << m_c << std::endl;
    }

};

int main() {
    std::vector<Parent> arr;
    Child c;
    Parent p;
    arr.push_back(c);
    arr.push_back(p);
    arr[0].print();
    arr[1].print();
    Parent &k = c;
    k.print();
    c.print();
    return 0;
}


/*
Some what intresting due to implicit conversion 

we get a new parent object 

May be obvious now that i know it 

I wanted to see what happens as I was expecting an error because Animal type and Child type
have different sizes unlike their pointers

So not possible to fit into an array but forgot that would just call a copy construtor 
and have Child implicitly converted to Parent.

*/
