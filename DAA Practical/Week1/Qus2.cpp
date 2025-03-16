/*
Given an already sorted array of positive integers, design an algorithm and implement it using a
program to find whether given key element is present in the array or not. Also, find total number
of comparisons for each input case. (Time Complexity = O(logn), where n is the size of input).
*/
//binary search

#include<iostream>
using namespace std;

int find_element(int arr[],int n,int key){

    int low=0 ,high=n-1, comp=0;
    
    while(low<=high){
        comp++;
        int mid=low +(high-low)/2;

        if(arr[mid]==key){
            cout<<"present  "<<endl;
            return comp;
        }else if(arr[mid]>key)
             high=mid-1;
        else
            low=mid+1;
    }
    cout<<"Not present "<<endl;
    return comp;
}


int main(){
    int n ,key;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
       cin>>arr[i];
    }
    cin>>key;

    cout<<"no of comparisons :"<<find_element(arr,n,key);
    return 0;
}