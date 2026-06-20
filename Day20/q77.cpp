#include <iostream>
#include <vector>
using namespace std;

int main() {
    int row1,col1,row2,col2;
    cout<<"Enter size of matrix 1(rows and columns)";
    cin >> row1>>col1;

    cout<<"Enter the size of matrix 2(rows and columns--Make sure the number of columns of 1st matrix is equal to the number of rows of 2nd matrix)";
    cin >> row2 >> col2;

    if (col1 != row2) {
    cout << "Matrix multiplication is not possible!" << endl;
    return 0;
}

    //matrix1
    vector<vector<int>> matrix1(row1, vector<int>(col1));
    cout<<"Enter the elements of the matrix1:\n";
    for (int i = 0; i < row1; i++)
        for (int j = 0; j < col1; j++)
            cin >> matrix1[i][j];

    //matrix2
    vector<vector<int>> matrix2(row2, vector<int>(col2));
    cout<<"Enter the elements of the matrix2:\n";
    for (int i = 0; i < row2; i++)
        for (int j = 0; j < col2; j++) 
            cin >> matrix2[i][j];

    cout << "The multiplication of matrix1 and matrix2 is: \n";
    for (int i = 0; i < row1; i++){
        for (int j = 0; j < col2; j++){
            int product = 0;
            for (int k = 0; k < col1; k++)
                product += matrix1[i][k] * matrix2[k][j];
            cout << product << " ";
        }
        cout << endl;
    }
}