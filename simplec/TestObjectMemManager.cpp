#include <iostream>
#include <unistd.h>
using namespace std;

class Test1 {

public:
    Test1() {
        std::cout << "test1 create: " << this << std::endl;
    }

    ~Test1() {
        std::cout << "test1 delete: " << this << std::endl;
    }

};

class Test2 {

public:
    Test1 test1;
    std::string str_;

    Test2() {
        str_ = random();
        std::cout << "test2 create: " << str_ << ":" << this << std::endl;
    }

    ~Test2() {
        std::cout << "test2 delete: " << str_ << ":" << this << std::endl;
    }

    void print() {
        std::cout << "I m test2: " << str_ << ":" << this << std::endl;
    }
};

class Test3 {
public:

    void setTest2(const Test2& test2) { test2_ = test2; }

    void print() {
        test2_.print();
    }

private:

    Test2 test2_;


};


int main(int argc, char *argv[]) {

    auto f = [](const Test2& test2) {
        std::cout << "function get test2" << std::endl;
    };

    Test3 test3;



//    {
//        Test2* test2 = new Test2();
//        std::shared_ptr<Test2> test2 = std::make_shared<Test2>();
        Test2 test2;
        test3.setTest2(test2);
        test3.print();
//    }

    test3.print();

    while (true) {
        test3.print();
        sleep(2);
    }

    return 0;
}