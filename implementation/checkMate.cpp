#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vi2 vector<vector<int>>
#define rep(i, a, b) for(int i = a;i<b;i++)
#define repd(i, a) for(int i = a;i>=0;i--)

bool isKingSafe(int kcol, int krow, int r1col, int r1row, int r2col, int r2row) {
    if((kcol > 8) || (kcol < 1) || (krow > 8) || (krow < 1)) return false;
    if((kcol != r1col) && (kcol != r2col) && (krow != r1row) && (krow != r2row)) return true;
    return false;
}

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
bool isCheckMate(int kcol, int krow, int r1col, int r1row, int r2col, int r2row) {
    if(((krow == r1row) && (abs(kcol - r1col) == 1)) || ((kcol == r1col) && (abs(krow - r1row) == 1)) || ((krow == r2row) && (abs(kcol - r2col) == 1)) || ((kcol == r2col) && (abs(krow - r2row) == 1))) return false;
    rep(i, 0, 8) {
        if(isKingSafe(kcol + dx[i], krow + dy[i], r1col, r1row, r2col, r2row)) return false;
    }
    return true;
}
  
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int kcol, krow, r1col, r1row, r2col, r2row;
        cin >> kcol >> krow;
        cin >> r1col >> r1row;
        cin >> r2col >> r2row;
        int flag = 0;
        if(isCheckMate(kcol, krow, r1col, krow, r2col, r2row)) flag = 1;
        else if(isCheckMate(kcol, krow, kcol, r1row, r2col, r2row)) flag = 1;
        else if(isCheckMate(kcol, krow, r1col, r1row, r2col, krow)) flag = 1;
        else if(isCheckMate(kcol, krow, r1col, r1row, kcol, r2row)) flag = 1;
        if(flag == 1) cout << "YES\n";
        else if(flag == 0) cout << "NO\n";
    }
    return 0;
}