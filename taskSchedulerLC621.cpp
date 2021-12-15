#include<bits/stdc++.h>
using namespace std;
//#define int                                                        long long
#define vi                                                         vector<int>
#define vvi                                                        vector<vector<int>>
#define pb(x)                                                      push_back(x)
#define ppb                                                        pop_back()
#define rep(i, a, b)                                               for(int i = a;i<b;i++)
#define repd(i, a)                                                 for(int i = a;i>=0;i--)
#define setbits(x)                                                 __builtin_popcountll(x)
#define FIO                                                        ios_base::sync_with_stdio(false); cin.tie(NULL);

int minimumCpuTime(vector<char>& tasks, int n, int num_of_tasks) {
    vi freq(26);
    for(auto it:tasks) freq[it - 'A']++;
    sort(freq.begin(), freq.end());
    int max_freq = freq[25];
    int idle_time = (max_freq - 1)*n;
    repd(i, 24) {
        if(idle_time <= 0) break;
        idle_time -= min(max_freq - 1, freq[i]);
    }
    idle_time = max(0, idle_time);
    return idle_time + num_of_tasks;
}

void solve() {
    int num_of_tasks;
    cin >> num_of_tasks;
    vector<char> tasks(num_of_tasks);
    for(auto &it:tasks) cin >> it;
    int n;
    cin >> n;
    cout << minimumCpuTime(tasks, n, num_of_tasks);
}

int main() {
    FIO;
    solve();
    return 0;
}