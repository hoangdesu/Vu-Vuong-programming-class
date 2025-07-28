#include <iostream>
#include "task.h"

using namespace std;

bool isSorted(const int *arr, const int logical_length, std::string order) {
    if (order != "ascending" && order != "descending") return false;

    // cout << "order = " << order << endl;

    for (int i = 0; i < logical_length - 1; i++) {
        int j = i+1;
        if (order == "ascending") {
            if (arr[j] < arr[i]) return false;
        } else if (order == "descending")  {
            if (arr[j] > arr[i]) return false;
        }
    }

    return true;
}

void prefixSumArray(const int *arr, int *prefix_sum, int logical_length) {
    // for (int i = 0; i < logical_length; i++) {
    //     int total = 0; // stack
    //     for (int j = 0; j <= i; j++) {
    //         total += arr[j];
    //     }
    //     prefix_sum[i] = total;
    // }

    for (int i = 0; i < logical_length; i++) {
        // prefix_sum[i] = 1;
        cout << "i = " << i << " - sum = " << prefix_sum[i] << endl;
    }
}
