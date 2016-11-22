#include <iostream>

using namespace std;

//Time: O(2n)
//Space: O(1)?

int* calculateProductArray(int* arr, int n) {
    int* prod = new int[5];
    int sum = 1;
    for (int i=0; i<n; i++) {
        prod[i] = sum;
        if (arr[i] == 0) {
            sum = 0;
        } else {
            sum *= arr[i];
        }
    }
    sum = 1;
    for (int i=n-1; i>-1; i--) {
        prod[i] = sum*prod[i];
        if (arr[i] == 0) {
            sum = 0;
        } else {
            sum *= arr[i];
        }
    }
    return prod;
}

int main() {
    int n = 5;
    int arr[n] = {10,1,5,6,2};
    int* prod = calculateProductArray(arr, n);
    for (int i=0; i<n; i++) {
        cout << prod[i] << " ";
    }
    delete[] prod;
    return 0;
}