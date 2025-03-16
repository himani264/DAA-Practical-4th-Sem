/*
Given a sorted array of positive integers, design an algorithm and implement it using a program
to find three indices i, j, k such that arr[i] + arr[j] = arr[k].
*/

#include <iostream>
#include <algorithm>  
using namespace std;

bool binary_search(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return true;
        } else if (arr[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return false;
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        bool found = false;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int sum = arr[i] + arr[j];

                int k = lower_bound(arr + j + 1, arr + n, sum) - arr;

                if (k < n && arr[k] == sum) {
                    cout << i + 1 << ", " << j + 1 << ", " << k + 1 << endl;
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        if (!found) cout << "No sequence found." << endl;
    }
    return 0;
}
