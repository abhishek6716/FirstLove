#include<iostream>
#include<climits>
using namespace std;

int max(int n, int m){
    if(n>m){
        return n;
    } else{
        return m;
    }
}

void sumOfArrays(int arr1[], int n, int arr2[], int m){
    int carry=0;
    int max1= max(n,m);
    int res[max1];
    int i=n-1;
    int j=m-1;
    int k=max1-1;
    res[0]=carry;
    while(i>=0 && j>=0){
        int sum = carry+arr1[i]+arr2[j];
        int ones = sum%10;
        int tens = sum/10;
        carry=tens;
        res[k]=ones;
        i--;
        j--;
        k--;
    }
    if(i==-1){
        while(j>=0){
            int sum = carry+arr2[j];
            int ones = sum%10;
            int tens = sum/10;
            carry=tens;
            res[k]=ones;
            j--;
            k--;
        }
    }
    if(j==-1){
        while(i>=0){
            int sum = carry+arr1[i];
            int ones = sum%10;
            int tens = sum/10;
            carry=tens;
            res[k]=ones;
            i--;
            k--;
        }
    }
    for(int i=0; i<max1; i++){
        cout<<res[i];
    }
}

int main(){
    int arr1[]={1,2,3,4,5,6,7};
    int arr2[]={5,6,7,8,9};
    sumOfArrays(arr1, 7, arr2, 5);
}