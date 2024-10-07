#include <iostream>
#include <string>
#include <vector>
#include <chrono>
using std::string;
using std::vector;
#include "StringData.h"

int linear_search(vector<string> container,string element) {
    for (int i = 0;i < container.size(); i++) {
        if (container[i] == element) {
            return i;
        }
    }
    return -1;
}

int binary(vector<string> container,string element) {
    int start = 0;
    int end = container.size()-1;
    int mid = (start + end)/2;

    while (start <= end) {
        if (container[mid] == element) {
            return mid;
        }
        else if (container[mid] < element) {
            start = mid + 1;
            mid = (start + end)/2;
        }
        else {
            end = mid - 1;
            mid = (start + end)/2;
        }
    }
    return - 1;
}

int main() {
    string element;
    vector<string> lists = getStringData();
    std::cout << "What are you searching for?";
    std::cin >> element;
    auto s = std::chrono::system_clock::now();
    std::cout << "Index (Linear Search): " << linear_search(lists,element) << std::endl;
    auto e = std::chrono::system_clock::now();
    std::chrono::duration<double> lduration = e - s;
    std::cout <<"Linear time: " << lduration.count() << " seconds" << std::endl;
    auto st = std::chrono::system_clock::now();
    std::cout << "Index (Binary Search): " << binary(lists,element) << std::endl;
    auto en = std::chrono::system_clock::now();
    std::chrono::duration<double> bduration = en - st;
    std::cout <<"Binary time: " << bduration.count() << " seconds" << std::endl;

    return 0;
}