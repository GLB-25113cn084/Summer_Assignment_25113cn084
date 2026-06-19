#include <iostream>
#include <vector>
using namespace std;

int main() {
    int size_mat;
    cout << "Enter size of matrices: ";
    cin >> size_mat;

    vector<vector<int>> matrix1(size_mat, vector<int>(size_mat));
    cout << "Enter the elements of matrix1:\n";
    for (int i = 0; i < size_mat; i++)
        for (int j = 0; j < size_mat; j++)
            cin >> matrix1[i][j];
    
    vector<vector<int>> matrix2(size_mat, vector<int>(size_mat));
    cout << "Enter the elements of matrix2:\n";
    for (int i = 0; i < size_mat; i++)
        for (int j = 0; j < size_mat; j++)
            cin >> matrix2[i][j];
    
    int ch;
    cout << "Do you want matrix1-matrix2 (1) or matrix2-matrix1 (2)? ";
    cin >> ch;

    int sign = (ch == 1) ? 1 : -1;
    cout << (ch == 1 ? "matrix1 - matrix2:\n" : "matrix2 - matrix1:\n");
    for (int i = 0; i < size_mat; i++) {
        for (int j = 0; j < size_mat; j++)
            cout << sign * (matrix1[i][j] - matrix2[i][j]) << " ";
        cout << endl;
    }
}
