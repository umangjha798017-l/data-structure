#include<iostream>

using namespace std;

int main()

{
    int arr[4]={10,20,30,40};
    
    int pos;

    cout<<"enter position to delete";

    cin>>pos;
    for(int i=pos;i<3;i++)
    {
        arr[i]=arr[i+1];

    }
    cout<<"array after deletion";
    for(int i=0;i<3;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;



}
