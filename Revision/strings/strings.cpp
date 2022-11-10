#include<iostream>
using namespace std;

int lengthOfStr(char str[]){
    int cnt=0;
    for(int i=0; str[i]!='\0'; i++){
        cnt++;
    }
    return cnt;
}

bool isPalindrome(char str[]){
    int len = lengthOfStr(str);
    int i=0; int j=len-1;
    while(i<j){
        if(str[i]==str[j]){
            i++;
            j--;
        } else{
            return false;
        }
    }
    return true;
}

int main(){
    char str[100];
    cin>>str;
    // cout<<lengthOfStr(str);
    cout<<isPalindrome(str);
}