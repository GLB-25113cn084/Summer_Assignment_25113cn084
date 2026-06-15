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
    cout<<"The array after rotating it right once is: [ ";
    temp = arr[n-1];
    for (int i = n-1; i > 0; i--)
        arr[i] = arr[i-1];
    arr[0] = temp;
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<"  ";
    cout<<"]";
}