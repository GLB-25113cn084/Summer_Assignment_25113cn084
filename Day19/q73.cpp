#include <iostream>
#include <vector>
using namespace std;

int main() {
    int row,col;
    cout<<"Enter size of matrices(rows and columns)";
    cin >> row>>col;

    //matrix1
    vector<vector<int>> matrix1(row, vector<int>(col));
    cout<<"Enter the elements of the matrix1:\n";
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> matrix1[i][j];

    //matrix2
    vector<vector<int>> matrix2(row, vector<int>(col));
    cout<<"Enter the elements of the matrix2:\n";
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++) 
            cin >> matrix2[i][j];

    cout << "The addition of matrix1 and matrix2 is: \n";
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++)
            cout << matrix1[i][j] + matrix2[i][j] << " ";
        cout << endl;
    }
}