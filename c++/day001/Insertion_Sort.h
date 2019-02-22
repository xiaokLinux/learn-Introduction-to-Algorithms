//
//  Insertion_Sort.hpp
//  DataStruct
//
//  Created by 彭芮 on 2019/2/21.
//  Copyright © 2019 pengrui. All rights reserved.
//

#ifndef Insertion_Sort_h
#define Insertion_Sort_h

#include <iostream>
using namespace std;
class Insertion_Sort{
public:
    Insertion_Sort();
    ~Insertion_Sort();
    
   void InsertionSort(int *arr,int len);
};

void InsertionSort(int *arr, int len)
{
    int key = 0;
    int i = 0;
    for (int j = 1; j < len; j++)
    {
        key = arr[j];
        //insert arr[j] into the sorted sequence arr[1..j-1]
        i = j-1;
        while (i >= 0 && arr[i] > key)
        {
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key;
    }
    for (int a = 0; a< 6; a++) {
      printf("arr[6] = %d", arr[a]);
    }

}


#endif /* Insertion_Sort_hpp */
