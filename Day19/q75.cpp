#include <iostream>
#include <vector>
using namespace std;

int main() {
    int size_mat;
    cout << "Enter size of matrices: ";
    cin >> size_mat;

    vector<vector<int>> matrix(size_mat, vector<int>(size_mat));
    cout << "Enter the matrix (each row on one line, space-separated):\n";
    for (int i = 0; i < size_mat; i++) 
        for (int j = 0; j < size_mat; j++)
            cin >> matrix[i][j];
    

    cout << "The transpose of the matrix is:\n";
    for (int i = 0; i < size_mat; i++) {
        for (int j = 0; j < size_mat; j++)
            cout << matrix[j][i] << " ";   
        cout << endl;
    }


}