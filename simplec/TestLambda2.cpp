#include <chrono>
#include <iostream>
#include <thread>
using namespace std;

typedef std::function<void(int result)> ResultCallback;

void f(ResultCallback resultCallback) {
    std::thread t([resultCallback] {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        cout << "in " << std::this_thread::get_id() << " " << &resultCallback << " " << endl;
        resultCallback(10);
    });
    t.detach();
    cout << "out " << std::this_thread::get_id() << " " << &resultCallback << " " << endl;
}

int main() {
    auto cb = [](int result) {
        cout << "done " << std::this_thread::get_id() << " " << result << " " << endl;
    };

    cout << "init " << std::this_thread::get_id() << " " << &cb << " " << endl;

    f(cb);
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
}

//out 0x10259c580 0x16d9a73e8
//in 0x16da2f000 0x13f606858
//done 0x16da2f000 10

// 为啥out和in引用不一样, 但是却能调用回去。实际上不要把c++的lambda理解成像Java的接口对象。这是不一样的概念。
// 你就理解成，这个cb被拷贝了多次，但实际上，它就像它的代码块被拷贝了多次一样。而且，如果这个cb lambda如果捕获外部变量了，这些变量可不是随着拷贝被拷贝，这些变量就是不动的。
// 不要搞迷，上面写的就当是的理解。
