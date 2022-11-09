#include<iostream>
using namespace std;

int arrayRotation(int arr[], int n){
    for(int i=0; i<n-1; i++){
        if(arr[i] > arr[i+1]){
            return i+1;
        }
    }
    return -1;
}

int main(){
    int arr[]={-1,0,1,2,3,4};
    cout<<arrayRotation(arr, 6);
}