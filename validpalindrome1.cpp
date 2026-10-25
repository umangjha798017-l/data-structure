#include<iostream>
#include<cstring>
using namespace std;
bool ispalindrome(char palin[],int n){
   
    int st=0,end=n-1;
    while(st<end){
        if(palin[st]!=palin[end]){
            cout<<"not valid palindrome"<<endl;
            return false;
            
        }
        st++;end--;
    }
    cout<<"valid palindrome"<<endl;
    return true;
}

int main(){
    char palin[100];
     cout<<"enter the letter =";
    cin>>palin;
    ispalindrome(palin,strlen(palin));
    return 0;
    
}