#include<bits/stdc++.h>
using namespace std;

int dx[] = {1,0};
int dy[] = {0,1};
string dir = "DR";

int pathsinamatrix(int i, int j, int row, int col, vector<vector<int>> &mat, string str) {
    if(i==row-1 && j==col-1) {
        int x;
        for(x = 0;x<str.length()-1;x++) cout << str[x] << "->";
        cout << str[x] << "\n";
        return 1;
    }
    if(i>=row || j>=col || mat[i][j]==1) return 0;
    int down = pathsinamatrix(i+dx[0], j+dy[0], row, col, mat, str + dir[0]);
    int right = pathsinamatrix(i+dx[1], j+dy[1], row, col, mat, str + dir[1]);
    return right + down;
}

int main() {
    int row, col;
    cout << endl << "Enter number of rows and columns: ";
    cin >> row >> col;
    int brow, bcol;
    cout << endl << "Enter blocked row and blocked column: ";
    cin >> brow >> bcol;
    vector<vector<int>> mat(row, vector<int>(col,0));
    mat[brow][bcol] = 1;
    cout << endl << "The matrix looks like this:" << endl;
    for(int i = 0;i<row;i++) {
        for(int j = 0;j<col;j++) cout << mat[i][j] << " ";
        cout << "\n";
    }
    string str = "";
    cout << endl << "The paths in the matrix are:" << endl;
    vector<vector<int>> vis(row, vector<int>(col, 0));
    cout << endl <<"The total number of possible paths in the matrix are :"<<pathsinamatrix(0, 0, row, col, mat, str);
    return 0;
}