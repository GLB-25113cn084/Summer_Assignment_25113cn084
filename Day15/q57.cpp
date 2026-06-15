#include <iostream>
using namespace std;

int main()
{
    int n,temp;
    cout<<"Enter the size of array: ";
    cin>>n; 
    int arr[n];

    for (int i = 0; i < n; i++)
        cin>>arr[i];

    cout<<"The array after reversing is: [ ";
    for (int i = 0; i < n/2; i++)
    {
        temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<"  ";
    cout<<"]";
}
