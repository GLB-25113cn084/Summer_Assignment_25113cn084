#include <iostream>
using namespace std;
int main()
{
    int n,sum=0,average;
    cout<<"Enter the size of array: ";
    cin>>n; 
    int arr[n];

    for (int i = 0; i < n; i++)
        cin>>arr[i];

    int even_count=0,odd_count=0;

    for (int i = 0; i < n; i++)
    {
        if(arr[i]%2==0)
            even_count++;
        else
            odd_count++;
    }
    cout<<"Number of even elements in the array is: "<<even_count<<endl;
    cout<<"Number of odd elements in the array is: "<<odd_count;
    return 0;
}