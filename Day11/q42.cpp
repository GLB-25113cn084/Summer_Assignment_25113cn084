#include <iostream>
using namespace std;

// for 2 nums
/*int maximum(int a,int b)
{
    if(a > b)
        return a;
    else
        return b;
}
int main()
{
    int a,b;
    cout << "Enter two numbers: ";
    cin>> a >> b;
    cout << "The maximum of " << a << " and " << b << " is: " << maximum(a,b) << endl;
    return 0;
}*/

// for more than 2 nums
int max(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int main()
{
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;

    int arr[size];
    cout << "Enter " << size << " numbers: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "The maximum number is: " << max(arr, size) << endl;
    return 0;
}