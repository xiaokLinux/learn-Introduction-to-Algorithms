//
//  main.cpp
//  DataStruct
//
//  Created by 彭芮 on 2019/2/22.
//  Copyright © 2019年 pengrui. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include "Selection_Sort.h"
using namespace std;


int main(int argc, const char * argv[])
{
    int arr[1000] = {0};
    for (int i = 0; i < 1000; i++) {
        arr[i] = rand();
    }
    SelectionSort(arr,sizeof(arr)/sizeof(arr[0]));
    
    return 0;
}
