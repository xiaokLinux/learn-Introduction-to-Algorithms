//
//  Merge.hpp
//  DataStruct
//
//  Created by 彭芮 on 2019/2/24.
//  Copyright © 2019 pengrui. All rights reserved.
// 分治法：把规模为n的问题，分解为k个规模较小的子问题，这些子问题互相独立且与原问题相同。递归解决这些子问题，然后将子问题的解合并为原问题的解
// Merge_Change算法为分治法的改写，不使用哨兵元素而是在一旦数组arrL或arrR中所有元素都被复制回数组arr后，就立即停止，再将另一个数组中余下的元素复制回数组Aarr

#ifndef Merge_h
#define Merge_h

#include <iostream>

using namespace std;

class Merge{
public:
    Merge();
    ~Merge();
    
    void merge(int *arr,int p, int q, int r); //q,p,r为下标元素
    void merge_Sort(int *arr, int p, int r);
    void Merge_Change(int *arr,int p, int q, int r); //q,p,r为下标元素
};

void merge(int *arr,int p, int q, int r)
{
    //创建左右两边的辅助数组
    int a1 = q - p + 1;
    int a2 = r - q;
    int *arrL = new int[a1+1];
    int *arrR = new int[a2+1];
    
    for (int i = 1; i <= a1; i++) {
        arrL[i] = arr[p+i-1];
    }
    for (int i = 1; i <= a2; i++) {
        arrR[i] = arr[q+i];
    }
    
    arrL[a1+1] = 1000;   //哨兵值，任意值就ok
    arrR[a2+1] = 1000;
    
    int i = 1;
    int j = 1;
    
    for (int k = p; k < r; k++) {
        if (arrL[i]<=arrR[j]) {
            arr[k] = arrL[i];
            i++;
        }
        else{
            arr[k] = arrR[j];
            j++;
        }
    }
}

void merge_Sort(int *arr, int p, int r)
{
    if (p<r) {
        int q = (p+r) / 2;
        merge_Sort(arr, p, r);
        merge_Sort(arr, q+1, r);
        merge(arr, p, q, r);
    }
}

void Merge_Change(int *arr, int p, int q, int r)
{
    //创建左右两边的辅助数组
    int a1 = q - p + 1;
    int a2 = r - q;
    int *arrL = new int[a1];
    int *arrR = new int[a2];
    
    for (int i = 0; i < a1; i++) {
        arrL[i] = arr[p+i];
    }
    for (int i = 0; i < a2; i++) {
        arrR[i] = arr[q+i+1];
    }
    
    int i = 0;
    int j = 0;
    int k = p;
    
    while ((i <= a1-1) &&( j <= a2-1)) {
        if (arrL[i] < arrR[j]) {
            arr[k] = arrL[i];
            i++;
        }
        else{
            arr[k] = arrR[j];
            j++;
        }
        k++;
    }
    
    while (i <= a1-1) {
        arr[k] = arrL[i];
        i++;
        k++;
    }
    while (j <= a2-1){
        arr[k] = arrR[j];
        j++;
        k++;
    }
    
    delete []arrL;
    delete []arrR;
}

#endif /* Merge_hpp */
