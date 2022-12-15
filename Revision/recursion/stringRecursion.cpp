#include<iostream>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;

void ReplaceChar(char str[], char c1, char c2){
    if(str[0]=='\0'){
        return;
    }
    ReplaceChar(str+1, c1, c2);
    if(str[0]==c1){
        str[0]=c2;
    }
}

void removeConseDup(char str[]){
    if(str[0]=='\0'){
        return;
    }
    removeConseDup(str+1);
    if(str[0]==str[1]){
        for(int i=0; str[i]!='\0'; i++){
            str[i]=str[i+1];
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////

void merge(int input[], int si, int m, int ei){
    int i=si, j=m+1, k=0;
    int arr[ei-si+1];
    while(i<=m && j<=ei){
        if(input[i]>input[j]){
            arr[k]=input[j];
            j++;
            k++;
        }
        else{
            arr[k]=input[i];
            i++;
            k++;
        }
    }
    if(i<=m){
        for(; i<=m; i++){
            arr[k]=input[i];
            k++;
        }
    }
    if(j<=ei){
        for(; j<=ei; j++){
            arr[k]=input[j];
            k++;
        }
    }
    // copying back to real array
   int l=0;
    for(int i=si; i<=ei; i++ ){
        input[i]=arr[l];
        l++;
    }
    
}
void sorting(int input[], int si, int ei){
    if(si>=ei){
        return;
    }
    int m=(si+ei)/2;
    sorting(input, si, m);
    sorting(input, m+1, ei);
    merge(input, si, m, ei);
}
void mergeSort(int input[], int size){
	sorting(input, 0, size-1);    
}

//////////////////////////////////////////////////////////////////////////////////////

int partitionArray(int input[], int start, int end)
{
    int pivot = input[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (input[i] <= pivot)
        {
            count++;
        }
    }
    int pivotIndex = start + count;
    int temp = input[start];
    input[start] = input[pivotIndex];
    input[pivotIndex] = temp;

    int i = start, j = end;
    while (i <= pivotIndex && j >= pivotIndex)
    {
        while (input[i] <= pivot)
        {
            i++;
        }
        while (input[j] > pivot)
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            int temp = input[i];
            input[i] = input[j];
            input[j] = temp;
            i++;
            j--;
        }
    }
    return pivotIndex;
}
void quickSort(int input[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int pivotIndex = partitionArray(input, start, end);
    quickSort(input, start, pivotIndex - 1);
    quickSort(input, pivotIndex + 1, end);
}
void quickSort(int input[], int n)
{
    quickSort(input, 0, n - 1);
}

//////////////////////////////////////////////////////////////////////////////////

int subStrings(string s, string res[]){
    if(s.empty()){
        res[0]="";
        return 1;
    }
    int subAns = subStrings(s.substr(1), res);
    for(int i=0; i<subAns; i++){
        res[i+subAns]=s[0]+res[i];
    }
    return 2*subAns;
}

void printSubSeq(string input, string output){
    if(input.length()==0){
        cout<<output<<endl;
        return;
    }
    printSubSeq(input.substr(1), output);
    printSubSeq(input.substr(1), output+input[0]);
}

////////////////////////////////////////////////////////////////////////////////

string getString(int n){
    if(n==2){
        return "abc";
    }
    if(n==3){
        return "def";
    }
    if(n==4){
        return "ghi";
    }
    if(n==5){
        return "jkl";
    }
    if(n==6){
        return "mno";
    }
    if(n==7){
        return "pqrs";
    }
    if(n==8){
        return "tuv";
    }
    if(n==9){
        return "wxyz";
    }
    return " ";
}

int keyPad(int n, string res[]){
    if(n==0){
        res[0]="";
        return 1;
    }
    int smallAns = keyPad(n/10, res);
    string options = getString(n%10);
    for(int i=0; i<options.length()-1; i++){
        for(int j=0; j<smallAns; j++){
            res[j+(i+1)*smallAns]=res[j];
        }
    }

    int k=0;
    for(int i=0; i<options.length(); i++){
        for(int j=0; j<smallAns; j++){
            res[k]=res[k]+options[i];
            k++;
        }
    }
    return smallAns*options.length();
}



void PrintKeypad(int n, string outputSoFar){
    if(n==0){
        cout<<outputSoFar<<endl;
        return;
    }
    string options=getString(n%10);
    for(int i=0; i<options.size(); i++){
        PrintKeypad(n/10, options[i]+outputSoFar);
    }
}

////////////////////////////////////////////////////////////////////////////////////

bool checkAB(char input[]){
    if(input[0]=='\0'){
        return false;
    }
    if(input[0]=='a'){
        if(input[1]=='\0'){
            return true;
        } else if(input[1]=='a'){
            return checkAB(input+1);
        } else if(input[1]=='b' && input[2]=='b'){
            if(input[3]=='a'){
                return checkAB(input+3);
            } else{
                return true;
            }
        } else{
            return false;
        }
    } else{
        return false;
    }
}

///////////////////////////////////////////////////////////////////////////////////////


int staircase(int n){
    if(n==1 || n==2){
        return n;
    }
    if(n==3){
        return 4;
    }
    return staircase(n-1)+staircase(n-2)+staircase(n-3);
}

//////////////////////////////////////////////////////////////////////////////////////

int binarySearchRecursive(int arr[], int si, int ei, int x){
    if(si>ei){
        return -1;
    }
    int mid=(si+ei)/2;
    if(arr[mid]==x){
        return mid;
    } else if(arr[mid]>x){
        return binarySearchRecursive(arr, si, mid-1, x);
    } else{
        return binarySearchRecursive(arr, mid+1, ei, x);
    }
}

int SearchRecursive(int arr[], int n, int x){
    return binarySearchRecursive(arr, 0, n-1, x);
}

////////////////////////////////////////////////////////////////////////////////////

int subSet(int arr[], int n, int output[][20]){
    if(n==0){
        output[0][0]=0;
        return 1;
    }
    int subAns=subSet(arr+1, n-1, output);
    for(int i=0; i<subAns; i++){
        output[i+subAns][0]=output[i][0]+1;
        output[i+subAns][1]=arr[0];
        for(int j=2; j<output[i][0]+2; j++){
            output[i+subAns][j]=output[i][j-1];
        }
    }
    return 2*subAns;
}

void printSubsetOfArrayHelper(int input[], int startIndex, int size, int output[], int oSize){
    if(startIndex==size){
        for(int i=0; i<oSize; i++){
            cout<<output[i]<<" ";
        }
        cout<<endl;
        return;
    }
    int smallOutput[40], smallOutputSize=0;
    printSubsetOfArrayHelper(input, startIndex+1, size, output, oSize);
    int i;
    for(int i=0; i<oSize; i++){
        smallOutput[i]=output[i];
    }
    smallOutput[i]=input[startIndex];
    printSubsetOfArrayHelper(input, startIndex+1, size, smallOutput, oSize+1);
}

void printSubsetOfArray2(int input[], int size, int output[], int oSize){
    if(size==0){
        for(int i=0; i<oSize; i++){
            cout<<output[i]<<" ";
        }
        cout<<endl;
        return;
    }
    int smallOutput[40], smallOutputSize=0;
    printSubsetOfArray2(input+1, size-1, output, oSize);
    int i;
    for(int i=0; i<oSize; i++){
        smallOutput[i]=output[i];
    }
    smallOutput[i]=input[0];
    printSubsetOfArray2(input+1, size-1, smallOutput, oSize+1);
}

void printSubsetOfArray(int input[], int size){
    int output[1000];
    // return printSubsetOfArrayHelper(input, 0, size, output, 0);
    return printSubsetOfArray2(input, size, output, 0);
}



int main(){
    // char str[100];
    // cin>>str;
    // char c1, c2;
    // cin>>c1>>c2;
    // ReplaceChar(str, c1, c2);
    // removeConseDup(str);
    // cout<<str<<endl;

    // int arr[100];
    // int n; cin>>n;
    // for(int i=0; i<n; i++){
    //     cin>>arr[i];
    // }
    // mergeSort(arr, n);
    // for(int i=0; i<n; i++){
    //     cout<<arr[i]<<" ";
    // }

    // string s;
    // cin>>s;
    // int n;
    // cin>>n;
    // string* res = new string[1000];
    // // int cnt = subStrings(s, res);
    // int cnt = keyPad(n, res);
    // for(int i=0; i<cnt; i++){
    //     cout<<res[i]<<endl;
    // }

    // char str[100];
    // cin>>str;
    // cout<<checkAB(str);

    // int n;
    // cin>>n;
    // cout<<staircase(n)<<endl;
   
    // int n; cin>>n;
    // int arr[50];
    // for(int i=0; i<n; i++){
    //     cin>>arr[i];
    // }
    // int output[20][20];
    // for(int i=0; i<20; i++){
    //     for(int j=0; j<20; j++){
    //         output[i][j]=-1;
    //     }
    // }
    // int ans=subSet(arr, n, output);
    // cout<<ans<<endl;
    // for(int i=0; i<ans; i++){
    //     for(int j=1; j<output[i][0]+1; j++){
    //         cout<<output[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    int arr[100]={1,2,3};
    int n=3;
    printSubsetOfArray(arr, n);
}