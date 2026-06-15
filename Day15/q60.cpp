#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n; 
    int arr[n];

    for (int i = 0; i < n; i++)
        cin>>arr[i];
    cout<<"the array after moving all zeros to the end is: [ ";
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
            arr[count++] = arr[i];
    }
    while (count < n)
        arr[count++] = 0;
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<"  ";
    cout<<"]";
}
