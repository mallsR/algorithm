//
//  quick_sort.hpp
//  algorithm
//
//  Created by xiaoR on 2023/8/24.
//

#ifndef quick_sort_hpp
#define quick_sort_hpp

#include <iostream>
#include <vector>
#include <cmath>

namespace quick_sort{
    using namespace std;

    void swap(vector<int> & arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    pair<int, int> partition(vector<int> & arr, int left, int right) {
        int less = left - 1; // 小于区左边界
        int more = right; // >区右边界
        while (left < more) {
    //        当前值小于划分值arr[right]，则需要改变小于区左边界，以及当前位置下标右移
            if (arr[left] < arr[right]) {
                swap(arr, ++less, left++);
            } else if (arr[left] > arr[right]) {
    //            当前值大于划分值，则将当前值调还到more - 1的位置，并且划分值仍然放在最右侧
                swap(arr, --more, left);
            } else {
    //            当前值等于划分值，小于区左边界不动，当前位置下标右移
                ++left;
            }
        }
    //    将划分值放到当前位置
        swap(arr, more, right);
        return {less + 1, more};
    }

    void quick_sort(vector<int> &arr, int left, int right) {
        if (left < right) {
    //        随机选择一个数替换right位置的数
            srand(time(NULL));
            swap(arr, rand() % (right - left + 1) + left, right);
    //        cout << "partition value : " << arr[right] << endl;
    //        寻找划分边界
            pair<int, int> border = partition(arr, left, right);
            quick_sort(arr, left, border.first - 1);
            quick_sort(arr, border.second + 1, right);
        }
    }
};

#endif /* quick_sort_hpp */
