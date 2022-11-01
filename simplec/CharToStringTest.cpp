#include <iostream>

int main() {

    char* ch = "abcd";
    // 这个方法涉及数据拷贝吗?
    std::string st(ch, 4);
    std::string st2 = ch;

    ch = "1234";
    std::cout << "st:" << st << std::endl;
    std::cout << "ch:" << ch << std::endl;
    std::cout << "st2:" << st2 << std::endl;
    return 0;
}
