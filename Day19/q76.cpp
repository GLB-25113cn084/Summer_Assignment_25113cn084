#include <iostream>
#include <vector>
using namespace std;

int main() {
    int size_mat,sum=0;
    cout << "Enter size of matrices: ";
    cin >> size_mat;

    vector<vector<int>> matrix(size_mat, vector<int>(size_mat));
    cout << "Enter the matrix (each row on one line, space-separated):\n";
    for (int i = 0; i < size_mat; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < size_mat; j++)
            cin >> matrix[i][j];
    }
    
    cout<<"The sum of diagnol is: ";
    for (int i = 0; i < size_mat; i++){
        for (int j = 0; j < size_mat; j++){
            if (i==j)
            {
                sum+=matrix[i][j];
            }
        }
    }
    cout<<sum;
    return 0;
}
            
