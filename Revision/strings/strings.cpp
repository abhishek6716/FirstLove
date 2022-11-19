#include<iostream>
#include<cstring>
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

void printAllPrefixes(char str[]){
    for(int i=0; str[i] != '\0'; i++){
        for(int j=0; j<=i; j++){
            cout<<str[j];
        }
        cout<<endl;
    }
    cout<<endl;
    
    for(int i=0; str[i] != '\0'; i++){
        for(int j=i; str[j] != '\0'; j++){
            cout<<str[j];
        }
        cout<<endl;
    }
    cout<<endl;

    for(int i=0; str[i] != '\0'; i++){
        for(int j=i; j>=0; j--){
            cout<<str[j];
        }
        cout<<endl;
    }
}

void printAllSubstrings(char str[]){
    for(int i=0; i<strlen(str); i++){
        for(int j=i; j<strlen(str); j++){
            for(int k=i; k<=j; k++){
                cout<<str[k];
            }
            cout<<endl;
        }
    }
}

bool isPermutation(char str1[], char str2[]){
    if(strlen(str1) != strlen(str2)){
        return false;
    }
    int arr[256] = {0};
    for(int i=0; i<strlen(str1); i++){
        arr[int(str1[i])]++;
    }
    for(int i=0; i<strlen(str1); i++){
        arr[int(str2[i])]--;
    }
    for(int i=0; i<256; i++){
        if(arr[i] != 0){
            return false;
        }
    }
    return true;
}

void removeConsecutiveDuplicates(char input[]){
    int i=0, k=1;
    while(k<=strlen(input)){
        if(input[i] != input[k]){
            input[i+1]=input[k];
            i++;
        } else{
            k++;
        }
    }
    cout<<input;
}

void reverseEachWord(char input[]){
    int i=0;
    for(int j=0; j<strlen(input); j++){
        if(input[j] == ' ' || j==strlen(input)-1){
            if(j==strlen(input)-1){
                reverse(input, i, j);
            } else{
                reverse(input, i, j-1);
                i=j+1;
            }
        }
    }
    cout<<input<<endl;
}

void removeX(char input[], char x){
    int k=0, i=0;
    while(input[i]!='\0'){
        if(input[i]!=x){
            input[k]=input[i];
            i++;
            k++;
        } else{
            i++;
        }
    }
    input[k]='\0';
    cout<<input<<endl;
}

char highestOccuringChar(char input[]){
    int arr[256] = {0};
    for(int i=0; i<strlen(input); i++){
        arr[input[i]]++;
    }
    int max=arr[0];
    int maxIndex=0;
    for(int i=0; i<256; i++){
        if(arr[i]>max){
            max=arr[i];
            maxIndex=i;
        }
    }
    return char(maxIndex);
}

void stringCompression(char input[]){
    int k=0, i=0;
    while(i<strlen(input)){
        char curr=input[i];
        int cnt=0;
        while(i<strlen(input) && input[i] == curr){
            i++;
            cnt++;
        }
        input[k]=curr;
        k++;
        if(cnt > 1) {
            string count_str = to_string(cnt);
            for(char &ch : count_str) {
                input[k] = ch;
                cnt++;
            }
        }
    }
    cout<<input<<endl;
}

int main(){
    char str1[100], str2[100];
    // cin>>str;
    // cout<<lengthOfStr(str);
    cin.getline(str1, 100);
    // cin.getline(str2, 100);
    // trimSpaces(str);
    // cout<<str;
    // printAllPrefixes(str);
    // printAllSubstrings(str);
    // cout<<isPermutation(str1, str2);
    // removeConsecutiveDuplicates(str1);
    // reverseEachWord(str1);
    // removeX(str1, 'b');
    // cout<<highestOccuringChar(str1)<<endl;
    stringCompression(str1);
}