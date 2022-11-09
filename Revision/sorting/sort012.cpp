#include<iostream>
using namespace std;

void sort012(int arr[], int n){
    int i=0; int k=0; int j=n-1;
    while(k<j){
        if(arr[k]==0){
            if(arr[i]==0){
                i++;
            } else if(arr[i]==1){
                arr[i]=0;
                arr[k]=1;
                i++;
                k++;
            } else{
                arr[i]=0;
                arr[k]=2;
                i++;
            }
        } else if(arr[k]==1){
            k++;
        } else{
            if(arr[j]==0){
                arr[j]=2;
                arr[k]=0;
                j--;
            } else if(arr[j]==1){
                arr[j]=2;
                arr[k]=1;
                j--;
                k++;
            } else{
                j--;
            }
        }
    }
}

int main(){
    int arr[]={0,1,2,1,0,0,2,0,2,0,1};
    sort012(arr, 11);
    for(int i=0; i<11; i++){
        cout<<arr[i]<<" ";
    }
}