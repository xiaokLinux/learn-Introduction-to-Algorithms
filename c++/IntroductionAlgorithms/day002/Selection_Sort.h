//
//  Selection_Sort.hpp
//  DataStruct
//
//  Created by 彭芮 on 2019/2/22.
//  Copyright © 2019 pengrui. All rights reserved.
//
//  选择排序：每一次从待排序的数据元素中选出最小或最大的一个元素，存放在序列的起始位置，然后，再从剩余未排序元素中继续寻找最小或最大元素，然后放到已排序序列的末尾

#ifndef Selection_Sort_h
#define Selection_Sort_h

#include <iostream>

using namespace std;

class Selection_Sort{
public:
    Selection_Sort();
    ~Selection_Sort();
    
    void SelectionSort(int *arr, int len);
};

void SelectionSort(int *arr, int len)
{
    int mix = 0;
    for (int j = 0;j< len-1; j++) {
        mix = j;
        for (int i = j+1; i < len; i++) {
            if (arr[i] < arr[mix]) {
                mix = i;
            }
        }
        if (j != mix) {
            int temp=arr[j];
            arr[j]=arr[mix];
            arr[mix]=temp;
        }
    }
    
    for (int a = 0; a < len; a++) {
        printf("arr[%d] = %d", a, arr[a]);
    }
}

#endif /* Selection_Sort_hpp */
