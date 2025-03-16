/*
Given an already sorted array of positive integers, design an algorithm and implement it using a
program to find whether a given key element is present in the sorted array or not. For an array
arr[n], search at the indexes arr[0], arr[2], arr[4],.....,arr[2k
] and so on. Once the interval (arr[2k
] < key < arr[ 2k+1] ) is found, perform a linear search operation from the index 2k
 to find the element
key. (Complexity < O(n), where n is the number of elements need to be scanned for searching):
Jump Search
*/


#include <iostream>
#include <cmath>
using namespace std;
void jumpSearch(int arr[], int n, int key)
{
    int step = sqrt(n), prev = 0, comparisons = 0;
    while (prev < n && arr[min(step, n) - 1] < key)
    {
        comparisons++;
        prev = step;
        step += sqrt(n);
        if (prev >= n)
        {
            cout << "Not Present " << comparisons << endl;
            return;
        }
    }
    // Perform linear search in the identified block
    while (prev < n && arr[prev] <= key)
    {
        comparisons++;
        if (arr[prev] == key)
        {
            cout << "Present " << comparisons << endl;
            return;
        }
        prev++;
    }
    cout << "Not Present " << comparisons << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, key;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cin >> key;
        jumpSearch(arr, n, key);
    }
    return 0;
}