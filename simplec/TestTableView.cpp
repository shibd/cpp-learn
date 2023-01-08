#include <iostream>
#include <unordered_map>
using namespace std;

struct TableView {
    std::unordered_map<std::string, std::string> m;

    const std::string &getValue(const std::string &key) const {
        static const std::string EMPTY;
        auto it = m.find(key);
        if (it == m.end()) {
            return EMPTY;
        } else {
            return it->second;
        }
    }

    void forEachAndListen(std::function<void(const std::string&, const std::string&)> callback) {


    }
};

//pkey: a a a c
//okey: 1 2 3 1


int main(int argc, char *argv[]) {
    TableView view;
    view.m["A"] = "A0";
    const auto &value = view.getValue("A");
    view.m.erase("A"); // 仅仅是示例，实际上可能因为 rehash，value 指向的地址实际上变成其他 key 的 value
    view.m["B"] = "B0";
    std::cout << value << std::endl; // 打印的是 B 对应的 value，造成了错误行为
    return 0;
}