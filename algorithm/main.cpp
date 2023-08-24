//
//  main.cpp
//  algorithm
//
//  Created by xiaoR on 2023/8/24.
//


#include "../sort/quick_sort.hpp"

using namespace std;

int main() {
//    测试
    vector<int> arr = {5, 0, 3, 4, 8, 5, 7, 2, 5, 5};
    quick_sort::quick_sort(arr, 0, arr.size() - 1);
//    打印输入
    for(auto num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
