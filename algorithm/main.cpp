//
//  main.cpp
//  algorithm
//
//  Created by xiaoR on 2023/8/24.
//


#include "../sort/quick_sort.hpp"
#include "../sort/heap_sort/heap_sort.hpp"
#include "sort_array_distance_lessK.hpp"

using namespace std;

int main() {
//    测试
//    vector<int> arr = {5, 0, 3, 4, 8, 5, 7, 2, 5, 5};
//    堆排序
//    quick_sort::quick_sort(arr, 0, arr.size() - 1);
//    heap_sort::heap_sort(arr);
    vector<int> arr = {5, 0, 2, 3, 4, 8, 5, 7, 5, 5};
    example::sort_array_distance_lessK(arr, 5);
//    打印输入
    for(auto num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
