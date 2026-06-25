#include <iostream>
#include <algorithm>
using namespace std;

void mergeSortedArrays(int a[], int m, int b[], int n, int result[]) {
    int i = 0, j = 0, k = 0;

    while (i < m && j < n) {
        if (a[i] <= b[j])
            result[k++] = a[i++];
        else
            result[k++] = b[j++];
    }

    while (i < m) result[k++] = a[i++];
    while (j < n) result[k++] = b[j++];
}

int main() {
    int m, n;

    cout << "Enter size of first array: ";
    cin >> m;
    int a[m];
    cout << "Enter " << m << " elements: ";
    for (int i = 0; i < m; i++) cin >> a[i];
    sort(a, a + m);

    cout << "Enter size of second array: ";
    cin >> n;
    int b[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(b, b + n);

    int result[m + n];
    mergeSortedArrays(a, m, b, n, result);

    cout << "Merged sorted array: ";
    for (int i = 0; i < m + n; i++)
        cout << result[i] << " ";
    cout << endl;

    return 0;
}
