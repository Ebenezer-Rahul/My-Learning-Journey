#include "./shared_ptr.hpp"
#include "./weak_ptr.hpp"
#include <string>

class Person  {
private:
verd::weak_ptr<Person> m_friend {};
std::string m_name {};

public:  
    Person() = default;
    Person(const char *name) {
        m_name = name;
    }

    void setFriend(const verd::shared_ptr<Person> &f) {
        m_friend = f;
    }
};


int main() { 
    using namespace verd;

    shared_ptr<Person> p1 {new Person("Rahul")};
    shared_ptr<Person> p2 {new Person("Eren")};

    p1->setFriend(p2);
    p2->setFriend(p1);

    std::cout << sizeof(std::string) << std::endl;

}