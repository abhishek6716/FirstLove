#include<iostream>
using namespace std;

void reverseArr(int arr[], int n){
    int i=0, j=n-1;
    while (i<j)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }
    
}

int main(){
    cout<<"enter size of array"; 
    int n;
    cin>>n;
    int arr[n];
    cout<<"enter elements of array";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    reverseArr(arr, n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

}