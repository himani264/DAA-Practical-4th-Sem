/*
Given an array of nonnegative integers, design a linear algorithm and implement it using a
program to find whether given key element is present in the array or not. Also, find total number
of comparisons for each input case. (Time Complexity = O(n), where n is the size of input)
*/

#include<iostream>
using namespace std;

int find_key(int arr[],int key ,int n){      
int comp=0 ;
for(int i=0;i<n;i++){
    comp++;
    if(arr[i]==key){
       cout<<"present ";
       return comp;
    }
}
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

    cout<<find_key(arr,key,n);
    return 0;

}