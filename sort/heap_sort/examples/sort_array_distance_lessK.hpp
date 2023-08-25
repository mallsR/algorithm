//
//  sort_array_distance_lessK.hpp
//  algorithm
//
//  Created by xiaoR on 2023/8/25.
//

#ifndef sort_array_distance_lessK_hpp
#define sort_array_distance_lessK_hpp

#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

namespace example{
using namespace std;
//    sort_array_distance_lessK
//    因为只需要简单的加入和弹出操作，则借助系统的的优先队列 ：此处建立小根堆
void sort_array_distance_lessK(vector<int> & arr, int k) {
    priority_queue<int, vector<int>, greater<int>> heap;
    int index = 0;
//    建小根堆：前k + 1个元素加入到堆中
//    fmin(arr.size(), k)，是为了确保k为极端值时也能运行
    for( ; index <= fmin(arr.size(), k); ++index) {
        heap.push(arr[index]);
    }
//    从左往右依次确定每个位置的元素
    int i = 0;
    for(; index < arr.size(); ++i, ++index) {
        heap.push(arr[index]);
//        确定i位置的元素
        arr[i] = heap.top();
        heap.pop();
    }
//    弹出剩余元素
    while (!heap.empty()) {
        arr[i++] = heap.top();
        heap.pop();
    }
}
}

#endif /* sort_array_distance_lessK_hpp */
