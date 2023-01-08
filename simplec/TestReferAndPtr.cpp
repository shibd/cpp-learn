#include <iostream>


class Test {


public:

    void setStr(const std::string& str) {

        std::cout << "1:" << &str << std::endl;
        t_str_ = str;

        std::cout << "2: " << &t_str_ << std::endl;
    }

    std::string t_str_;

};

int main() {
    std::string str = "s";
    std::string& str2 = str;
    auto str_p = &str;

    str2 = "sd";

    std::cout << str << std::endl;
    std::cout << str2 << std::endl;
    std::cout << *str_p << std::endl;
    std::cout << "0:" << str_p << std::endl;

    Test t;
    t.setStr(str);
//    t.setStr(str2);
//    t.setStr(*str_p);

    return 0;
}
