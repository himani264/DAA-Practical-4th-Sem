/*
Given an unsorted array of integers, design an algorithm and implement a program to sort this
array using selection sort. Your program should also find number of comparisons and number of
swaps required.
Input Format:
The first line contains number of test cases, T.
For each test case, there will be two input lines.
First line contains n (the size of array).
Second line contains space-separated integers describing array.
Output Format:
The output will have T number of lines.
For each test case T, there will be three output lines.
First line will give the sorted array.
Second line will give total number of comparisons.
Third line will give total number of swaps required.
*/

#include <iostream>
using namespace std;
void selectionSort(int arr[], int n, int &comparisons, int &swaps)
{
    comparisons = 0;
    swaps = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            comparisons++;
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        if (minIndex != i)
        {
            swap(arr[i], arr[minIndex]);
            swaps++;
        }
    }
}
// Driver function
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
        int comparisons = 0, swaps = 0;
        selectionSort(arr, n, comparisons, swaps);
        // Output sorted array
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << "\ncomparisons = " << comparisons;
        cout << "\nswaps = " << swaps << endl;
    }
    return 0;
}