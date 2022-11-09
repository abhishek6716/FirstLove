#include<iostream>
using namespace std;

void merge2SortedArr(int arr1[], int n, int arr2[], int m, int res[], int k){
    int i=0; int j=0; int l=0;
    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            res[l]=arr1[i];
            l++;
            i++;
        } else{
            res[l]=arr2[j];
            l++;
            j++;
        }
    }
    if(i<n){
        for(; i<n; i++){
            res[l]=arr1[i];
        }
    }
    if(j<m){
        for(; j<m;j++){
            res[l]=arr1[j];
        }
    }
}

int main(){
    int arr1[]={1,4,6,8,9,12};
    int arr2[]={2,5,10};
    int res[9];
    merge2SortedArr(arr1, 6, arr2, 3, res, 9);
    for(int i=0; i<9; i++){
        cout<<res[i]<<" ";
    }
}