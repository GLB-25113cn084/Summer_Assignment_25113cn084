#include <iostream>
using namespace std;

int main()
{
    int n,frequency=0,element;
    cout<<"Enter the size of array: ";
    cin>>n; 
    int arr[n];

    for (int i = 0; i < n; i++)
        cin>>arr[i];
    
    cout<<"enter the element whose freuqncy you want to find its frequency";
    cin>>element;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element)
            frequency++;
    }
    cout<<"Frequency of "<<element<<" is: "<<frequency<<endl;
}