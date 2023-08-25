//
//  main.cpp
//  algorithm
//
//  Created by xiaoR on 2023/8/24.
//


#include "quick_sort.hpp"
#include "heap_sort.hpp"
#include "sort_array_distance_lessK.hpp"
#include "radix_sort.hpp"

#include <iostream>

using namespace std;

int main() {
//    测试数据
    vector<int> arr = {5, 0, 3, 4, 8, 5, 7, 2, 5, 5};
//    快速排序
//    quick_sort::quick_sort(arr, 0, arr.size() - 1);
//    ---------------------------------
//    堆排序
//    heap_sort::heap_sort(arr);
//    vector<int> arr = {5, 0, 2, 3, 4, 8, 5, 7, 5, 5};
//    example::sort_array_distance_lessK(arr, 5);
//    ---------------------------------
//    基数排序
    Radix::radix_sort(arr);
//    打印输出
    for(auto num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
