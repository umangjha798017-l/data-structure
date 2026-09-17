#include<iostream>

using namespace std;

int main()
{
  int arr[100],n;

  cout<<"enter size of array";

  cin>>n;

  cout<<"enter"<<n<<"element";
   for(int i=0;i<n;i++)
   
    cin>>arr[i];

   
   cout<<"enter new value";
   int val;

   cin>>val;

   cout<<"enter position";

   int pos;

    cin>>pos;

   for(int i=n-1;i>=pos-1;i--)

   arr[i+1]=arr[i];

   arr[pos-1]=val;

   cout<<"element after insertion";

   for(int i= 0;i<=n;i++)
   cout<<arr[i]<<" ";

   return 0;

}

  

