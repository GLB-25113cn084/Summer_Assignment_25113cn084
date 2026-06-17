#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cout<<"enter the size of an array 1 and array 2 ";
    cin>>n>>m;
    int arr1[n],arr2[m],arr[100],k=0;

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
                int a;
                for(a=0;a<k;a++)
                {
                    if(arr[a]==arr1[i])
                        break;
                }
                if(a==k)
                {
                    arr[k++]=arr1[i];
                }
            }
        }
    }
    for(int i=0;i<k;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"]"<<endl;
    return 0;
}