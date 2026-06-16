#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int k = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[i - 1])
        {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }

    int newLength = removeDuplicates(nums);

    cout << "Array after removing duplicates: [ ";
    for (int i = 0; i < newLength; i++)
        cout << nums[i] << " ";
    cout<<"]";

    cout << "\nLength = " << newLength;

    return 0;
}