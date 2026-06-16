#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"enter the size of an array";
    cin>>n;
    int arr[n],missing_number;
    cout<<"enter the elements of an array"<<endl;
    for(int i=0;i<n;i++)
        cin>>arr[i];

    for(int i=1;i<=n;i++)
    {
        bool found=false;
        for(int j=0;j<n-1;j++)
        {
            if(arr[j]==i)
            {
                found=true;
                break;
            }
        }
        if(!found)
        {
            missing_number=i;
            break;
        }
    }
    cout<<"the missing number is "<<missing_number;
    return 0;
}