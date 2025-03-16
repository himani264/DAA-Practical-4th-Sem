/*
Given an unsorted array of integers, design an algorithm and implement it using a program to
find Kth smallest or largest element in the array. (Worst case Time Complexity = O(n))

*/

#include <iostream>
#include <algorithm>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int left, int right) {
    int pivot = arr[right]; 
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}


int quickSelect(int arr[], int left, int right, int k) {
    if (left <= right) {
        int mid = partition(arr, left, right);

        if (mid == k)
            return arr[mid];

        else if (mid > k)
            return quickSelect(arr, left, mid - 1, k);

        else
            return quickSelect(arr, mid + 1, right, k);
    }
    return -1;  
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cin >> k;

        cout << "Kth Smallest Element: " << quickSelect(arr, 0, n - 1, k - 1) << endl;
    }
    return 0;
}
