//
//  radix_sort.hpp
//  algorithm
//
//  Created by xiaoR on 2023/8/25.
//

#ifndef radix_sort_hpp
#define radix_sort_hpp

#include <stdio.h>
#include <iostream>

namespace Radix{
    using namespace std;

/// 找到arr中最大的数的位数
/// - Parameter arr: 待处理数组
int max_biit(vector<int> arr) {
//    找到最大的数
    int max = INT_MIN;
    for(int num : arr) {
        max = fmax(max, num);
    }
//    确定最大数的位数
    int result = 0;
    while (max) {
        ++result;
        max /= 10;
    }
    return result;
}

int get_digit_bit(int value, int i) {
    while (i > 1) {
        value /= 10;
        --i;
    }
    return value % 10;
}

/// 基数排序核心代码
/// - Parameters:
///   - arr: 待排序数组 ：可以利用left和right指定排序区间
///   - left: 左边界
///   - right: 右边界
///   - digit: 数据的最大位数
void radix(vector<int> & arr, int left, int right, int digit) {
    if (left >= right) {
        return;
    }
//    默认为10进制位
    int radix_num = 10;
//    需要right - left + 1个辅助空间
    vector<int> bucket(right - left + 1, 0);
//    需要进行digit次入桶出桶
    for(int d = 1; d <= digit; ++d) {
//        实现上有一些不同
//        count[0]表示当前位（d位）是0的数字有多少个
//        count[1]表示当前位（d位）是0,1的数字有多少个
//        count[2]表示当前位（d位）是0,1,2的数字有多少个
//        剩下的count[3]~count[9]依次类推
        vector<int> count(radix_num, 0);
//        遍历，统计digit位，各数的出现次数
        for(int i = left; i <= right; ++i) {
            int j = get_digit_bit(arr[i], d);
            count[j]++;
        }
//        累加count，作前缀和
        for(int i = 1; i < radix_num; ++i) {
            count[i] += count[i - 1];
        }
//        从右往左遍历arr，根据count统计以及从右往左的顺序性确定元素arr[i]的位置，放入bucket中：入桶操作
        for(int i = right; i >= left; --i) {
            int j = get_digit_bit(arr[i], d);
            bucket[count[j] - 1] = arr[i];
            count[j]--;
        }
//        将bucket拷贝到arr数组中：出桶操作
        for(int i = left, j = 0; i <=  right; ++i, ++j) {
            arr[i] = bucket[j];
        }
    }
}

// 基数排序main
void radix_sort(vector<int> & arr) {
    if (arr.size() < 2) {
        return;
    }
    radix(arr, 0, arr.size() - 1, max_biit(arr));
}
};

#endif /* radix_sort_hpp */
