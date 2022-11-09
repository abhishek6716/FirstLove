#include<iostream>
using namespace std;

void pushZeroesToEnd(int arr[], int n){
    int i=0; int k=0;
    while(i<n){
        if(arr[i] != 0){
            int temp=arr[k];
            arr[k]=arr[i];
            arr[i]=temp;
            k++;
            i++;
        } else{
            i++;
        }
    }
}

int main(){
    int arr[]={0,2,0,7,0,0,3,1,5,0,8,9};
    pushZeroesToEnd(arr, 12);
    for(int i=0; i<12; i++){
        cout<<arr[i]<<" ";
    }
}