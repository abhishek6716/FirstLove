#include<iostream>
using namespace std;


void sort012(int arr[], int n){
    
}

int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort012(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}