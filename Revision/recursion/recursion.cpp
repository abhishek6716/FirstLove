#include<iostream>
using namespace std;
#include<cmath>
#include<cstring>

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

int firstIndex(int arr[], int n, int x){
    if(n==1){
        if(arr[0]==x){
            return 0;
        } else{
            return -1;
        }
    }
    int smallAns = firstIndex(arr+1, n-1, x);
    if(arr[0]==x){
        return 0;
    } else{
        return smallAns+1;
    }
}

int lastIndex(int arr[], int n, int x){
    if(n==0){
        return -1;
    }
    int smallAns = lastIndex(arr+1, n-1, x);
    if(smallAns == -1){
        if(arr[0]==x){
            return 0;
        } else{
            return -1;
        }
    } else{
        return smallAns+1;
    }
}

int findAllIndexes(int arr[], int n, int x, int output[]){
    if(n==0){
        return 0;
    }
    int smallAns = findAllIndexes(arr+1, n-1, x, output);
    if(smallAns){
        if(arr[0]==x){
            for(int i=smallAns; i>=0; i--){
                output[i]=output[i-1];
                output[i]++;
            }
            output[0]=0;
            return smallAns+1;
        } else{
            for(int i=smallAns-1; i>=0; i--){
                output[i]++;
            }
            return smallAns;
        }
    } else{
        if(arr[0]==x){
            output[0]=0;
            return 1;
        } else{
            return 0;
        }
    } 
}

int findAllIndexes2(int arr[], int n, int x, int output[]){
    if(n==0){
        return 0;
    }
    int smallAns = findAllIndexes2(arr, n-1, x, output);
    if(smallAns){
        if(arr[n-1]==x){
            output[smallAns]=n-1;
            smallAns++;
            return smallAns;
        } else{
            return smallAns;
        }
    } else{
        if(arr[n-1]==x){
            output[0]=n-1;
            return 1;
        } else{
            return 0;
        }
    }
}

int multiplicationRec(int a, int b){
    if(a==0){
        return 0;
    }
    int smallAns=multiplicationRec(a-1, b);
    return smallAns+b;
}

int countZeroes(int n){
    if(n/10 == 0){
        if(n==0){
            return 1;
        } else{
            return 0;
        }
    }

    int smallAns = countZeroes(n/10);
    if(n%10 == 0){
        return smallAns+1;
    } else{
        return smallAns;
    }
}

double geometricSum(int k){
    if(k==0){
        return 1;
    }
    double ans=geometricSum(k-1);
    double a=1/(pow(2, k));
    return ans+a;
}

bool helper(char input[], int start, int end)
{
    if (end <= 0)
    {
        return true;
    }
    if (input[start] != input[end])
    {
        return false;
    }
    return helper(input, start + 1, end - 1);
}
bool Ispelindrome(char input[])
{
    int len = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        len++;
    }
    cout << len << endl;
    return helper(input, 0, len - 1);
}

int sumOfDigits(int n){
    if(n>=0 && n<=9){
        return n;
    }
    return sumOfDigits(n/10) + n%10;
}

void replacePi(char str[]){
    if(strlen(str)<=1){
        return;
    }
    replacePi(str+1);
    if(str[0]=='p' && str[1]=='i'){
        for(int i=strlen(str); i>=0; i--){
            str[i+2]=str[i];
        }
        str[0]='3';
        str[1]='.';
        str[2]='1';
        str[3]='4';
    }
}

void removeX(char str[]){
    if(strlen(str) <=0){
        return;
    }
    removeX(str+1);
    if(str[0]=='x'){
        for(int i=0; i<strlen(str); i++){
            str[i]=str[i+1];
        }
    }
}

int stringToNoHelper(char str[], int n){
    if(n==1){
        return str[0]-'0';
    }
    int smallAns = stringToNoHelper(str, n-1);
    return smallAns*10+(str[n-1]-'0');
}

int stringToNo(char str[]){
    return stringToNoHelper(str, strlen(str));
}

int stringToNo2(char input[]){
    int n=strlen(input);
    if(n==1){
        int a=input[0]-'0';
        return a;
    }
    int y=stringToNo2(input+1);
    int x=input[0]-'0';
    x=x*pow(10, n-1)+y;
    return x;
}

void pairStar(char str[]){
    if(strlen(str)<=1){
        return;
    }
    pairStar(str+1);
    if(str[0]==str[1]){
        for(int i=strlen(str); i>0; i--){
            str[i+1]=str[i];
        }
        str[1]='*';
    }
}

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 0){  
        return;  
    }  
    towerOfHanoi(n - 1, source, destination, auxiliary);  
    cout<<source<<" "<<destination<< endl;  
    towerOfHanoi(n - 1, auxiliary, source, destination); 
}

int main(){
    // int x; cin>>x;
    char n[100]; cin>>n;
    int arr[8]={6,2,7,4,8,6,6,6};
    int output[100];
    char str[8]={'a', 'b', 'c', 'd', 'd', 'c', 'b', 'a'};
    /// x^n
    // cout<<power(x, n);
    // printNNaturalNumbers(n);
    // printNNaturalNumbersInReverse(n);
    // cout<<noOfDigits(n)<<" ";
    // cout<<nthFiboNo(n)<<" ";
    // cout<<sumOfArr2(arr, 6)<<" ";
    // cout<<isPresent(arr, 6, 10)<<" ";
    // int resLen = findAllIndexes(arr, 8, 6, output);
    // cout<<resLen<<endl;
    // for(int i=0; i<resLen; i++){
    //     cout<<output[i]<<" ";
    // }
    // cout<<multiplicationRec(5, 98)<<endl;
    // cout<<countZeroes(90660780)<<endl;
    // cout<<geometricSum(3)<<endl;
    // cout<<Ispelindrome(str)<<endl;
    // cout<<sumOfDigits(12345)<<endl;
    // removeX(n);
    // cout<<stringToNo(n)<<endl;
    pairStar(n);
    cout<<n<<endl;
}