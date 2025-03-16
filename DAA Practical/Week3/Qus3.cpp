/*
I. Given an unsorted array of positive integers, design an algorithm and implement it using a
program to find whether there are any duplicate elements in the array or not. (use sorting) (Time
Complexity = O(n log n))

Input Format:
The first line contains number of test cases, T.
For each test case, there will be two input lines.
First line contains n (the size of array).
Second line contains space-separated integers describing array.
Output Format:
The output will have T number of lines.
For each test case, output will be 'YES' if duplicates are present otherwise ‘NO’
*/

#include <iostream>
#include <algorithm> 
using namespace std;
bool hasDuplicates(int arr[], int n)
{
    sort(arr, arr + n); 
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
            return true;
    }
    return false;
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
        cout << (hasDuplicates(arr, n) ? "YES" : "NO") << endl;
    }
    return 0;
}