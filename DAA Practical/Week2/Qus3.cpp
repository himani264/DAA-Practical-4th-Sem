/*
Given an array of nonnegative integers, design an algorithm and a program to count the number
of pairs of integers such that their difference is equal to a given key, K.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int count_numbers(int arr[], int n, int key)
{
    int count = 0;
    sort(arr, arr + n);
    int i = 0, j = 1;
    while (j < n)
    {
        int diff = arr[j] - arr[i];
        if (diff == key)
        {
            count++;
            i++, j++;
        }
        else if (diff < key)
            j++;
        else
            i++;
    }
    return count;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, K;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cin >> K;
        cout << count_numbers(arr, n, K) << endl;
    }
    return 0;
}