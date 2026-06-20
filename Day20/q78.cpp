#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int size_mat;
    cout << "Enter size of matrices: ";
    cin >> size_mat;

    vector<vector<int>> matrix(size_mat, vector<int>(size_mat));
    cout << "Enter the matrix (each row on one line, space-separated):\n";
    for (int i = 0; i < size_mat; i++) {
        cout<<"Row "<<i+1<<" :-";
        for (int j = 0; j < size_mat; j++)
            cin >> matrix[i][j];
    }
    bool symmetric = true;
    for (int i = 0; i < size_mat && symmetric; i++) {
        for (int j = 0; j < size_mat; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                symmetric = false;
                break;
            }
        }
    }
    if (symmetric)
        cout << "The matrix is symmetric.";
    else
        cout << "The matrix is non-symmetric.";
    
}