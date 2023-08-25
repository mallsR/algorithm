//
//  heap_sort.hpp
//  algorithm
//
//  Created by xiaoR on 2023/8/25.
//

#ifndef heap_sort_hpp
#define heap_sort_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

// 一下代码以大根堆为例
//----------------------
namespace heap_sort {
    using namespace std;
// 自动变量记录节点数量
int heap_size = 0;

// 交换两个位置的元素
void swap(vector<int> & arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

//    建堆过程
void heap_insert(vector<int> & arr, int index) {
//    当前位置的值一直比其父节点大（(i - 1) / 2）
//    暗含两个停止条件：当前位置不大于父节点；当前位置已经是初位置
    while (arr[index] > arr[(index - 1) >> 1]) {
//        交换两个位置的值
        swap(arr, index, (index - 1) / 2);
//        改变索引
        index = (index - 1) / 2;
    }
    ++heap_size;
}

// 获取堆顶元素
int get_val(vector<int> arr) {
    if (heap_size > 0) {
        return arr[0];
    }
    return -1;
}

// heapify
void heapify(vector<int> & arr, int index, int heap_size) {
//    左孩子下标
    int left = index * 2 + 1;
//    循环条件：还有孩子
    while (left < heap_size) {
//        最大的孩子下标
        int largest = (left + 1) < heap_size && arr[left + 1] > arr[left] ? left + 1 : left;
//        父节点和较大的孩子比较
        largest = arr[largest] > arr[index] ? largest : index;
//        父节点较大
        if (largest == index) {
            break;
        }
//        孩子较大
        swap(arr, largest, index);
        index = largest;
        left = index * 2 + 1;
    }
}

// 删除堆顶元素 ： 将最后的元素放到堆顶，并利用heapify调整位置
void delete_top(vector<int> & arr) {
    arr[0] = arr[--heap_size];
    heapify(arr, 0, heap_size);
}

// 如果比较特别，随机更改堆中的一个元素的值

// 堆排序：利用大根堆，则是从小到大排序
void heap_sort(vector<int> & arr) {
    if (arr.size() < 2) {
        return;
    }
//    建堆
//    for (int i = 0; i < arr.size(); ++i) {
//        heap_insert(arr, i);
//    }
//    更快的建堆
    for (int i = arr.size() - 1; i >=0; --i) {
        heapify(arr, i, arr.size() - 1);
    }
    
    heap_size = arr.size();
//  将堆顶元素放到最后一个位置：注意已经到其应该到的位置
    swap(arr, 0, --heap_size);
    while (heap_size > 0) {
        heapify(arr, 0, heap_size);
        swap(arr, 0, --heap_size);
    }
}

}

#endif /* heap_sort_hpp */
