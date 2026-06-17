#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cout<<"enter the size of an array 1 and array 2 ";
    cin>>n>>m;
    int arr1[n],arr2[m];

    cout<<"enter the elements of an array 1"<<endl;
    for(int i=0;i<n;i++)
        cin>>arr1[i];

    cout<<"enter the elements of an array 2"<<endl;
    for(int i=0;i<m;i++)
        cin>>arr2[i];
    
    cout<<"The intersection of the two arrays is [ ";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr1[i]==arr2[j])
            {
                cout<<arr1[i]<<" ";
                break;
            }
        }
    }
    cout<<"]"<<endl;
    return 0;
}