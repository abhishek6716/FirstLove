#include<iostream>
using namespace std;

void columnWiseSum(int **arr, int m, int n){
    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=0; j<m; j++){
            sum+=arr[j][i];
        }
        cout<<sum<<" ";
    }
}

void printArrColmnWise(int **arr, int m, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<arr[j][i]<<" ";
        }
        cout<<endl;
    }
}

void printArrRowWise(int **arr, int m, int n){
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
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<arr[j][i]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<"////////// column wise sum /////////////"<<endl;
    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=0; j<m; j++){
            sum+=arr[j][i];
        }
        cout<<sum<<" ";
    }
    cout<<endl;
}