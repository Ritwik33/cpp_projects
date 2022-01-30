#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mult(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
    vector<vector<int>> prod(mat1.size(), vector<int>(mat2[0].size()));
    for(int i = 0;i<mat1.size();i++) {
        for(int j = 0;j<mat2[0].size();j++) {
            int temp = 0;
            for(int k = 0;k<mat1[0].size();k++) {
                temp += mat1[i][k]*mat2[k][j];
            }
            prod[i][j] = temp;
        }
    }
    return prod;
}

void disp(vector<vector<int>>& mat) {
    for(int i = 0;i<mat.size();i++) {
        for(int j = 0;j<mat[i].size();j++) cout << mat[i][j] << " ";
        cout << "\n";
    }
}

int main() {
    int row1, col1, row2, col2;
    cout << "Enter dimensions of first matrix: ";
    cin >> row1 >> col1;
    vector<vector<int>> mat1(row1, vector<int>(col1));
    cout << "Enter dimensions of second matrix: ";
    cin >> row2 >> col2;
    vector<vector<int>> mat2(row2, vector<int>(col2));
    cout << "Enter elements of first matrix row-wise:\n";
    for(int i = 0;i<row1;i++) {
        for(int j = 0;j<col1;j++) cin >> mat1[i][j];
    }
    cout << "Enter elements of second matrix row-wise:\n";
    for(int i = 0;i<row2;i++) {
        for(int j = 0;j<col2;j++) cin >> mat2[i][j];
    }
    vector<vector<int>> prod(row1, vector<int>(col2));
    prod = mult(mat1, mat2);
    cout << "The resultant matrix is:\n\n";
    disp(prod);
    return 0;
}