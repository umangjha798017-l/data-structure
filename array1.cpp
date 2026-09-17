#include<iostream>

using namespace std;

int main ()
{
    int arr[100],n;

    cout<<"enter size of aaray";

    cin>>n;

    cout<<"enter"<<n<<"values";

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];

    }
    cout<<"you had entered the value";

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";

    }
    cout<<"\ninsert new value";
    for(int i=0;i<=n;i++)

    {
        cout<<arr[i]<<" ";

    }
    return 0; 

}