#include <chrono>
#include <iostream>
#include <thread>
using namespace std;

void f() {
    int x = 0;
    int a[1];  // do nothing
    std::thread t([&x] {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        cout << std::this_thread::get_id() << " " << &x << " " << x << endl;
    });
    t.detach();
    cout << std::this_thread::get_id() << " " << &x << " " << x << endl;
}

int main() {
    f();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}
