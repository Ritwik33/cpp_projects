#include<bits/stdc++.h>
using namespace std;

int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
string dir = "DLRU";

void ratinamatrix(int i, int j, int row, int col, vector<vector<int>> &mat, vector<vector<int>> &vis, string path) {
    if(i==row-1 && j==col-1) {
        int x;
        cout << "\n";
        for(x = 0;x<row;x++) {
            for(int y = 0;y<col;y++) cout << vis[x][y] << " ";
            cout << "\n";
        }
        cout << "\n";
        for(x = 0;x<path.length()-1;x++) cout << path[x] << "->";
        cout << path[x] << "\n";
        return;
    }
    if(i>=row || j>=col || i<0 || j<0 || mat[i][j]==1 || vis[i][j]==1) return;
    vis[i][j] = 1;
    for(int x = 0;x<4;x++) {
        ratinamatrix(i+dx[x], j+dy[x], row, col, mat, vis, path + dir[x]);
    }
    vis[i][j] = 0;
}

int main() {
    int row, col;
    cout << "\nEnter number of rows and columms: ";
    cin >> row >> col;
    vector<vector<int>> mat(row, vector<int>(col, 0));
    vector<vector<int>> vis(row, vector<int>(col, 0));
    cout << "\nEnter the elements:\n";
    for(int i = 0;i<row;i++) {
        for(int j = 0;j<col;j++) cin >> mat[i][j];
    }
    cout << "\nThe matrix is:\n";
    for(int i = 0;i<row;i++) {
        for(int j = 0;j<col;j++) cout << mat[i][j] << " ";
        cout << "\n";
    }
    string path = "";
    cout << "\nThe paths are:\n";
    ratinamatrix(0, 0, row, col, mat, vis, path);
    return 0;
}