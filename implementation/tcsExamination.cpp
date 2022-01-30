#include<bits/stdc++.h>
using namespace std;
#define int                                                        long long
#define vi                                                         vector<int>
#define vvi                                                        vector<vector<int>>
#define pb(x)                                                      push_back(x)
#define ppb                                                        pop_back()
#define rep(i, a, b)                                               for(int i = a;i<b;i++)
#define repd(i, a)                                                 for(int i = a;i>=0;i--)
#define setbits(x)                                                 __builtin_popcountll(x)
#define FIO                                                        ios_base::sync_with_stdio(false); cin.tie(NULL);
#define w(t)                                                       int t; cin >> t; while(t--)

void solve() {
   w(t) {
       vi dragon, sloth;
       rep(i, 0, 3) {
           int grade;
           cin >> grade;
           dragon.pb(grade);
       }
       rep(i, 0, 3) {
           int grade;
           cin >> grade;
           sloth.pb(grade);
       }
       int dragonTotal = accumulate(dragon.begin(), dragon.end(), 0);
       int slothTotal = accumulate(sloth.begin(), sloth.end(), 0);
       if(dragonTotal > slothTotal) {
           cout << "Dragon\n";
       } else if(slothTotal > dragonTotal) {
           cout << "Sloth\n";
       } else {
           if(dragon[0] > sloth[0]) {
               cout << "Dragon\n";
           } else if(sloth[0] > dragon[0]) {
               cout << "Sloth\n";
           } else {
               if(dragon[1] > sloth[1]) {
                   cout << "Dragon\n";
               } else if(sloth[1] > dragon[1]) {
                   cout << "Sloth\n";
               } else {
                   if(dragon[2] > sloth[2]) {
                       cout << "Dragon\n";
                   } else if(sloth[2] > dragon[2]) {
                       cout << "Sloth\n";
                   } else {
                       cout << "Tie\n";
                   }
               }
           }
       }
   }
}

signed main() {
    FIO;
    solve();
    return 0;
}