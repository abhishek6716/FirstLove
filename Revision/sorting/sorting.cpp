#include<iostream>
using namespace std;

void selectionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int min=arr[i+1];
        int minIndex=i+1;
        for(int j=i+1; j<n; j++){
            if(min>arr[j]){
                min=arr[j];
                minIndex=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[minIndex];
        arr[minIndex]=temp;
    }
}


void bubbleSort(int arr[], int n){
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<i; j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void insertionSort(int arr[], int n){
    for(int i=0; i<n; i++){
        int curr=arr[i];
        int j;
        for(j=i-1; j>=0; j--){
            if(curr<arr[j]){
                arr[j+1]=arr[j];
            } else{
                break;
            }
        }
        arr[j+1]=curr;
    }
}

int main(){
    int arr[] = {6, 5, 8, 3, 4, 2, 1, 7};
    // selectionSort(arr, 8);
    // bubbleSort(arr, 8);
    insertionSort(arr, 8);
    for(int i=0; i<8; i++){
        cout<<arr[i]<<" ";
    }
}