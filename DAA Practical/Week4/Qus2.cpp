/*
Given an unsorted array of integers, design an algorithm and implement it using a program to
sort an array of elements by partitioning the array into two subarrays based on a pivot element
such that one of the sub array holds values smaller than the pivot element while another sub
array holds values greater than the pivot element. Pivot element should be selected randomly
from the array. Your program should also find number of comparisons and swaps required for
sorting the array.
*/

#include<iostream>
#include<algorithm>
using namespace std;
int comparisons=0;
int swaps=0;


void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
    swaps++;
}

int partition(int arr[],int left,int right){
    int x=arr[right];
    int i=left-1;

    for(int j=left;j<right;j++){
        comparisons++;
        if(arr[j]<=x){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[right],arr[i+1]);
    return i+1;
}

void quick_sort(int arr[],int left ,int right){

   if(left <right){
     int mid= partition(arr,left,right);
    quick_sort(arr,left,mid-1);
    quick_sort(arr,mid+1 ,right);
   }
}

int main(){
    int T, n;
    cin >> T;
    while (T--) {
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    quick_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\nComparisons = " << comparisons << "\n";
    cout << "Swaps = " << swaps << "\n";
    }
    return 0;
}