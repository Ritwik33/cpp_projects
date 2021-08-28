#include<bits/stdc++.h>
using namespace std;

int dx[] = {1, 1, 0, -1, 0, 1, -1, -1};
int dy[] = {0, 1, -1, 1, 1, -1, 0, -1};
string dir = "DELNRSUW";

void ratinamaze(int i, int j, int row, int col, vector<vector<int>> &mat, vector<vector<int>> &vis, string path) {
    if(i==row-1 && j==col-1) {
        for(int ii=0;ii<row;ii++) {
            for(int jj=0;jj<col;jj++) cout << vis[ii][jj] << " ";
            cout << "\n";
        }
        cout << "\n";
        int x;
        for(x = 0;x<path.length()-1;x++) cout << path[x] << "->";
        cout << path[x];
        cout << "\n\n";
        return;
    }
    if(i>=row || j>=col || i<0 || j<0 || mat[i][j]==1 || vis[i][j]==1) return;
    vis[i][j] = 1;
    for(int x = 0;x<8;x++) {
        ratinamaze(i+dx[x], j+dy[x], row, col, mat, vis, path + dir[x]);
    }
    vis[i][j] = 0;
}

int main() {
    int row, col;
    cout << "\nEnter number of rows and columns: ";
    cin >> row >> col;
    vector<vector<int>> mat(row, vector<int>(col, 0));
    vector<vector<int>> vis(row, vector<int>(col, 0));
    cout << "\nEnter the maze\n(path: 0, obstacle: 1):\n";
    for(int x = 0;x<row;x++) {
        for(int y = 0;y<col;y++) cin >> mat[x][y];
    }
    cout << "\nThe maze looks like this:\n";
    for(int i = 0;i<row;i++) {
        for(int j = 0;j<col;j++) cout << mat[i][j] << " ";
        cout << "\n";
    }
    string path = "";
    cout << "\nThe potential paths for the rat are:\n\n";
    ratinamaze(0, 0, row, col, mat, vis, path);
    return 0;
}