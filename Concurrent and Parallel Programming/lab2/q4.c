//4. Suppose you are building a C++ string class that you intend to use in a multithreaded program. You are worried
//about your string objects possibly getting corrupted if they are updated by more than one thread at a time. You
//consider adding a mutex as a member of each string and locking that mutex whenever any string method is
//called. Discuss the implications of this design. Write a main program to test your C++ String class.

#include <iostream>
#include <string>
#include <mutex>

class MyString {
public:
    MyString() : data(""), mutex() {}

    void append(const std::string& str) {
        std::lock_guard<std::mutex> lock(mutex);
        data += str;
    }

    std::string get() {
        std::lock_guard<std::mutex> lock(mutex);
        return data;
    }

private:
    std::string data;
    std::mutex mutex;
};

int main() {
    MyString myStr;
    std::vector<std::thread> threads;

    for (int i = 0; i < 4; ++i) {
        threads.emplace_back([&myStr, i]() {
            myStr.append("Thread " + std::to_string(i) + " ");
        });
    }

    for (auto& thread : threads) {
        thread.join();
    }

    std::string result = myStr.get();
    std::cout << "Final String: " << result << std::endl;

    return 0;
}

