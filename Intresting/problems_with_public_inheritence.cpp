
/*

B b1;
B b2;
A& a_ref = b2;
a_ref = b1;

now b2 contains parts of b1 and b2

Because B inherits publicly from A

This is also called object slicing


I also think this is why public inheritence is bad in c++


*/




/*

SOLUTION

class A {
public:
  virtual A& operator= (const A& a) {
    assign(a);
    return *this;
  }

protected:
  void assign(const A& a) {
    // copy members of A from a to this
  }
};

class B : public A {
public:
  virtual B& operator= (const A& a) {
    if (const B* b = dynamic_cast<const B*>(&a))
      assign(*b);
    else
      throw bad_assignment();
    return *this;
  }

protected:
  void assign(const B& b) {
    A::assign(b); // Let A's assign() copy members of A from b to this
    // copy members of B from b to this
  }
};

*/