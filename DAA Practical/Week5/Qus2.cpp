/*
. Given an unsorted array of integers, design an algorithm and implement it using a program to
find whether two elements exist such that their sum is equal to the given key element. (Time
Complexity = O(n log n)
*/

#include <iostream>
#include <algorithm>
using namespace std;
void findPairWithSum(int arr[], int n, int key)
{
    sort(arr, arr + n); 
    int left = 0, right = n - 1;
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == key)
        {
            cout << arr[left] << " " << arr[right] << endl;
            return;
        }
        else if (sum < key)
            left++;
        else
            right--;
    }
    cout << "No Such Element Exist\n";
}
int main()
{
    int n, key;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> key;
    findPairWithSum(arr, n, key);
    return 0;
}