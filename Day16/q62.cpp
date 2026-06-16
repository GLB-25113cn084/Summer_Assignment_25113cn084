#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"enter the size of an array";
    cin>>n;
    int arr[n];
    cout<<"enter the elements of an array"<<endl;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"The element with the highest frequency is ";
    int max_count=0,element;
    for(int i=0;i<n;i++)
    {
        int count=1;
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j])
                count++;
        }
        if(count>max_count)
        {
            max_count=count;
            element=arr[i];
        }
    }
    cout<<element<<" with frequency "<<max_count;
    return 0;
}