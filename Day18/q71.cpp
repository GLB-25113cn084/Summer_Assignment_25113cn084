//binary search
#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) 
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid; 
        else if (arr[mid] < target)
            left = mid + 1; 
        else
            right = mid - 1; 
    }
    return -1; 
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];

    cout << "Enter the elements : ";
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
    
    //sorting the array using bubble sort
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    int target;
    cout << "Enter the target element to search: ";
    cin >> target;

    cout<< "Sorted array: ";
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";
    cout<<endl;
    int result = binarySearch(arr, n, target);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }
    return 0;
}