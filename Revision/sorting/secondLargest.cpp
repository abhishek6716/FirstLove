#include<iostream>
#include<climits>
using namespace std;

int secondLargest(int arr[], int n){
    int max1,max2;
    max1=max2=INT_MIN;
    for(int i=0; i<n; i++){
        if(arr[i] > max1 && arr[i] > max2){
            max2=max1;
            max1=arr[i];
        } else if(arr[i] < max1 && arr[i] > max2){
            max2=arr[i];
        } else{
            continue;
        }
    }
    return max2;
}

int main(){
    int arr[]={5,6,3,2,9,1,4,8};
    cout<<secondLargest(arr, 8);
}