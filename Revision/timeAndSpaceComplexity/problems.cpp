#include<iostream>
#include<algorithm>
using namespace std;

// using XOR(^) gate
// 1^0=1
// 0^1=1
// 0^0=0
// 1^1=0

// time complexity   o(n)
// space complexity  o(1) 

int findUnique(int arr[], int n){
    int res=arr[0];
    for(int i=1; i<n; i++){
        res = res ^ arr[i];
    }
    return res;
}

int Duplicate2(int arr[], int n){
    int duplicate=0;
    for(int i=1; i<=n-2; ++i){
        duplicate=duplicate^i;
    }
    for(int i=0; i<n; ++i){
        duplicate=duplicate^arr[i];
    }
    return duplicate;
}

int Duplicate1(int arr[], int n){
    int sum1=0;
    for(int i=0; i<n; i++){
        sum1=sum1+arr[i];
    }
    n=n-1;
    int sum2=(n*(n-1))/2;
    int duplicate=sum1-sum2;
    return duplicate;
}

void ArrayIntersection(int input1[], int input2[], int size1, int size2){
    sort(input1, input1+size1);
    sort(input2, input2+size2);

    int i=0, j=0;
    while(i<size1 && j<size2){
        if(input1[i]==input2[j]){
            cout<<input1[i]<<" ";
            i++;
            j++;
        }
        else if(input1[i]<input2[j]){
            i++;
        }
        else{
            j++;
        }
    }
}

void PairSum(int arr[], int size, int x){
    sort(arr, arr+size);
    int left=0;
    int right=size-1;
    while(left<right){
        if(arr[left]+arr[right]<x){
            left++;
        }
        else if(arr[left]+arr[right]>x){
            right--;
        }
        else{
            int tempLeft=arr[left];
            int leftCount=0;
            while(arr[left]==tempLeft){
                leftCount++;
                left++;
            }

            int tempRight=arr[right];
            int pairCount;
            if(tempLeft==tempRight){
                pairCount=(leftCount*(leftCount-1))/2;
            }
            else{
                int rightCount=0;
                while(arr[right]==tempRight){
                    rightCount++;
                    right--;
                }
                pairCount=leftCount*rightCount;
            }
            while(pairCount--){
                cout<<tempLeft<<" "<<tempRight<<endl;
            }
        }
    }
}

void TripletSum(int input[], int size, int x){
    
    sort(input, input+size);
    
    for(int i=0; i<size; i++){
        int start=i+1;
        int end=size-1;
        int val=x-input[i];
        while(start<end){
            if(input[start]+input[end]>val){
                end--;
            }
            else if(input[start]+input[end]<val){
                start++;
            }
            else{
                int count1=0, count2=0;
                for(int ptr=start; ptr<=end; ptr++){
                    if(input[ptr]==input[start]){
                        count1++;
                    }
                    else{
                        break;
                    }
                }
                for(int ptr=end; ptr>=start; ptr--){
                    if(input[ptr]==input[end]){
                        count2++;
                    }
                    else{
                        break;
                    }
                }
                int combinations=count1*count2;
                if(input[start]==input[end]){
                    combinations=((end-start+1)*(end-start))/2;
                }
                for(int k=0; k<combinations; k++){
                    cout<<input[i]<<" "<<input[start]<<" "<<input[end]<<endl;
                }
                start=start+count1;
                end=end-count2;
            }
        }
    }
}

void rotateArrLeftByK(int arr[], int n, int k){
    for(int i=0; i<k; i++){
        int temp=arr[0];
        for(int j=1; j<n; j++){
            arr[j-1]=arr[j];
        }
        arr[n-1]=temp;
    }
}

void rotateArrLeftByK2(int arr[], int n, int k){
    int temp[100];
}

int main(){
    int arr[100]={1,2,3,4,5,6,7};
    int n=7;
    rotateArrLeftByK(arr, n, 3);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

}