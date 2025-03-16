/*
Problem 1: Merge Sort with Comparisons and Inversions
Statement: Given an unsorted array of integers, sort it using Merge Sort and count the number of
comparisons and inversions.
Approach
● Merge Sort: A divide-and-conquer algorithm that splits the array, sorts each half, and
merges them.
● Comparisons: Counted when merging two subarrays.
● Inversions: Counted when a larger element appears before a smaller one in sorting.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int comparisons = 0;
int inversions = 0;

void merge(int arr[], int left, int mid, int right)
{

    int n1 = mid - left + 1;
    int n2 = right - mid;

    int arr1[n1], arr2[n2];

    for (int i = 0; i < n1; i++)
        arr1[i] = arr[left + i];

    for (int i = 0; i < n2; i++)
        arr2[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2){
        comparisons++;
        if (arr1[i] <= arr2[j]){
            arr[k] = arr1[i];
            i++;
        }
        else{
            arr[k] = arr2[j];
            j++;
            inversions++;
        }
        k++;
    }

    while (i < n1){
        arr[k] = arr1[i];
        i++, k++;
    }

    while (j < n2){
        arr[k] = arr2[j];
        j++, k++;
    }
}

void merge_sort(int arr[], int left, int right){
   
    int mid = left + (right - left) / 2;

    if (left >= right)
        return;

    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

int main()
{
    int T, n;
    cin >> T;
    while (T--)
    {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        merge_sort(arr, 0, n - 1);

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";

        cout << "\nComparisons = " << comparisons << "\n";
        cout << "Inversions = " << inversions << "\n";
    }
    return 0;
}