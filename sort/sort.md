# 排序

# 排序

---

## O(N^2)性能差的原因

1. 浪费了很多的比较行为。每次都需要比较N次才确定一个数。

## 归并排序

1. 复杂度
    1.  $O(NlogN)$
    2. 比较行为传递下去，进行更高层次的比较
2. 框架
    
    ```cpp
    void process(vector<int> & nums, int left, int right) {
        if (left == right) {
            return;
        }
        int mid = left + ((right -  left) >> 1);
        process(nums, left, mid);
        process(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }
    ```
    

### 实际问题

1. 小和问题
    1. [1, 3, 4, 2, 5] ，总共产生16个小和
2. 逆序对

## 快速排序

1. 选取一个值进行划分
    1. 如果每次都选择固定位置的树，则时间复杂度为O(N^2)因为划分值很偏，造成极端情况。
2. 最好随机选值，能较好地避开最差情况，复杂度就变为$O(NlogN)$
    
    ```cpp
    
    ```
    

### 实际问题

1. 荷兰国旗问题（三色问题）
2.