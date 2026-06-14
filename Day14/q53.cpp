#include <iostream>
using namespace std;

int main()
{
    int n,find;
    cout<<"Enter the size of array: ";
    cin>>n; 
    int arr[n],index;

    for (int i = 0; i < n; i++)
        cin>>arr[i];

    cout<<"Enter the element to be searched: ";
    cin>>find;
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == find)
        {
            found = true;
            index = i;
            break;
        }
    }
    if (found)
        cout<<"Element found in the array at index = "<<index;
    else
        cout<<"Element not found in the array.";
    return 0;
}