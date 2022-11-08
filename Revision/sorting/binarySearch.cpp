#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int k){
    int left=0; int right=n-1;
    while (left<right){
        int mid=(left+right)/2;
        if(arr[mid]==k){
            return mid;
        } else if(arr[mid]>k){
            right=mid-1;
        } else{
            left=mid+1;
        }
    }
    return -1;
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    cout<<binarySearch(arr, 9, 7);
}