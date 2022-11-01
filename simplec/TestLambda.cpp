#include <chrono>
#include <iostream>
#include <thread>
using namespace std;

void f() {
    int x = 0;
    std::thread t([&x] {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        cout << "in " << std::this_thread::get_id() << " " << &x << " " << x << endl;
    });
    t.detach();
    cout << "out " << std::this_thread::get_id() << " " << &x << " " << x << endl;
}

int main() {
    f();
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
}


//g++ TestLambda.cpp -std=c++11 -pthread
// a.out
//out 0x103160580 0x16d0ab3dc 0
//in 0x16d133000 0x16d0ab3dc 1
