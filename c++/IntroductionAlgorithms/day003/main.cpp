//
//  main.cpp
//  DataStruct
//
//  Created by 彭芮 on 2019/2/24.
//  Copyright © 2019年 pengrui. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include "Merge.h"
using namespace std;


int main(int argc, const char * argv[])
{
    int arr[] = {3,9,41,52,26,38,49,57};
    
    Merge_Change(arr, 0, 3, 7);
    
    for (int a = 0; a< sizeof(arr)/sizeof(arr[0]); a++) {
        printf("arr[%d] = %d\n", a, arr[a]);
    }
    
    int arr1[] = {3,9,41,52,26,38,49,57};
    
    merge(arr1, 0, 3, 7);
    
    for (int a = 0; a< sizeof(arr1)/sizeof(arr1[0]); a++) {
        printf("arr1[%d] = %d\n", a, arr1[a]);
    }
    
    return 0;
}
