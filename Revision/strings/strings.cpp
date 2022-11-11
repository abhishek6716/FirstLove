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

void replaceChar(char str[], char s1, char s2){
    for(int i=0; str[i]!='\0'; i++){
        if(str[i]==s1){
            str[i]=s2;
        }
    }
}

void reverseStr(char str[]){
    int len = lengthOfStr(str);
    int i=0, j=len-1;
    while(i<j){
        char temp=str[i];
        str[i]=str[j];
        str[j]=temp;
        i++;
        j--;
    }
}

void trimSpaces(char str[]){
    int i=0, j=0;
    while(str[i] != '\n'){
        if(str[i] == ' '){
            i++;
        } else{
            str[j]=str[i];
            i++;
            j++;
        }
    }
}

void reverse(char input[], int start, int end){
    int i=start, j=end;
    while(i<j){
        char temp=input[i];
        input[i]=input[j];
        input[j]=temp;
        i++;
        j--;
    }
}
void reverseStringWordWise(char input[]){
    int previousSpaceIndex=-1;
    int i=0;
    while(input[i] != '\0'){
        if(input[i]==' '){
            reverse(input, previousSpaceIndex+1, i-1);
            previousSpaceIndex=i;
        }
        i++;
    }
    reverse(input, previousSpaceIndex+1, i-1);
    reverse(input, 0, i-1);
}

int main(){
    char str[100];
    // cin>>str;
    // cout<<lengthOfStr(str);
    cin.getline(str, 100);
    trimSpaces(str);
    cout<<str;
}