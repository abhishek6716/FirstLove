#include<iostream>
using namespace std;

int power(int x, int n){
    if(n==1){
        return x;
    }
    int res = power(x, n-1);
    return x*res;
}

void printNNaturalNumbers(int n){
    if(n==1){
        cout<<1<<" ";
        return;
    }
    printNNaturalNumbers(n-1);
    cout<<n<<" ";
}

void printNNaturalNumbersInReverse(int n){
    if(n==1){
        cout<<1<<" ";
        return;
    }
    cout<<n<<" ";
    printNNaturalNumbersInReverse(n-1);
}

int noOfDigits(int n){
    if(n>0 && n<10){
        return 1;
    }
    return noOfDigits(n/10)+1;
}

// 0 1 1 2 3 5 8 13
// 0 1 2 3 4 5 6 7   nth

int nthFiboNo(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return nthFiboNo(n-1)+nthFiboNo(n-2);
}

bool isArrSorted1(int arr[], int n){
    if(n<=1){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }
    return isArrSorted1(arr+1, n-1);
}

bool isArrSorted2(int arr[], int n){
    if(n<=1){
        return true;
    }
    bool smallAns = isArrSorted2(arr+1, n-1);
    if(smallAns){
        if(arr[0]>arr[1]){
            return false;
        } else{
            return true;
        }
    } else{
        return false;
    }
}

int sumOfArr1(int arr[], int n){
    if(n==1){
        return arr[0];
    };
    return sumOfArr1(arr+1, n-1)+arr[0];
}

int sumOfArr2(int arr[], int n){
    if(n==1){
        return arr[0];
    }
    return sumOfArr2(arr, n-1)+arr[n-1];
}

bool isPresent(int arr[],int n, int x){
    if(n==1){
        if(arr[0]==x){
            return true;
        } else{
            return false;
        }
    }

    bool smallAns = isPresent(arr+1, n-1, x);
    if(smallAns){
        return true;
    } else{
        if(arr[0]==x){
            return true;
        } else{
            return false;
        }
    }
}

int main(){
    // int x; cin>>x;
    // int n; cin>>n;
    int arr[6]={1,2,3,4,5,6};
    /// x^n
    // cout<<power(x, n);
    // printNNaturalNumbers(n);
    // printNNaturalNumbersInReverse(n);
    // cout<<noOfDigits(n)<<" ";
    // cout<<nthFiboNo(n)<<" ";
    // cout<<sumOfArr2(arr, 6)<<" ";
    cout<<isPresent(arr, 6, 10)<<" ";
}