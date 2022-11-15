#include<iostream>
using namespace std;

void spiralPrint(int arr[][100], int m, int n){
    int i, k = 0, l = 0;
    /* k - starting row index
        m - ending row index
        l - starting column index
        n - ending column index
        i - iterator
    */
    while (k < m && l < n) {
        for (i = l; i < n; ++i) {
            cout << arr[k][i] << " ";
        }
        k++;
 
        for (i = k; i < m; ++i) {
            cout << arr[i][n - 1] << " ";
        }
        n--;
 
        if (k < m) {
            for (i = n - 1; i >= l; --i) {
                cout << arr[m - 1][i] << " ";
            }
            m--;
        }
 
        if (l < n) {
            for (i = m - 1; i >= k; --i) {
                cout << arr[i][l] << " ";
            }
            l++;
        }
    }
}

void wavePrint(int arr[][100], int m, int n){
    for(int j=0; j<n; j++){
        if(j%2==0){
            for(int i=0; i<m; i++){
                cout<<arr[i][j]<<" ";
            }
        } else{
            for(int i=m-1; i>=0; i--){
                cout<<arr[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}

void largestRowOrColumn(int arr[][100], int m, int n){
    bool isrow = true;
    int index, sum=0;
    for(int i=0; i<m; i++){
        int sum1=0;
        for(int j=0; j<n; j++){
            sum1+=arr[i][j];
        }
        if(sum1>sum){
            sum=sum1;
            index=i;
            isrow=true;
        }
    }
    for(int i=0; i<n; i++){
        int sum2=0;
        for(int j=0; j<m; j++){
            sum2+=arr[j][i];
        }
        if(sum2>sum){
            sum=sum2;
            index=i;
            isrow=false;
        }
    }
    if(isrow){
        cout<<"row "<<index<<" "<<sum<<endl;
    }
}

void columnWiseSum(int arr[][100], int m, int n){
    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=0; j<m; j++){
            sum+=arr[j][i];
        }
        cout<<sum<<" ";
    }
    cout<<endl;
}

void printArrColmnWise(int arr[][100], int m, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<arr[j][i]<<" ";
        }
        cout<<endl;
    }
}

void printArrRowWise(int arr[][100], int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int arr[100][100];
    cout<<"enter no of rows";
    int m; cin>>m;
    cout<<"enter no of columns";
    int n; cin>>n;
    cout<<endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    cout<<endl;
    printArrRowWise(arr, m, n);
    cout<<endl;
    printArrColmnWise(arr, m, n);
    cout<<endl;
    columnWiseSum(arr, m, n);
    cout<<endl;
    largestRowOrColumn(arr, m ,n);
    cout<<endl;
    wavePrint(arr, m, n);
    cout<<endl;
    spiralPrint(arr, m, n);
    cout<<endl;
}