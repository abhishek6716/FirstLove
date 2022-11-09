#include<iostream>
using namespace std;

void rotateArr(int arr[], int n, int d){
    for(int i=0; i<d; i++){
        int temp=arr[0];
        for(int j=0; j<n-1; j++){
            arr[j]=arr[j+1];
        }
        arr[n-1]=temp;
    }
}

int main(){
    int arr[]={1,2,3,4,5,6,7};
    rotateArr(arr, 7, 3);
    for(int i=0; i<7; i++){
        cout<<arr[i]<<" ";
    }
}