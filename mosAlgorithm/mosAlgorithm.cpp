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
#define endl                                                       '\n'

class query {
    public:
    int l, r, id;
};

int a[200000], b = sqrt(200000), ans[200000], sum;

bool comp(const query& q1, const query& q2) {
    return q1.l/b < q2.l/b or (q1.l/b == q2.l/b and q1.r < q2.r);
}

void add(int i) {
    sum += a[i];
}

void rem(int i) {
    sum -= a[i];
}

int32_t main() {
    FIO;
    int n, q; cin >> n >> q;
    rep(i, 0, n) cin >> a[i];
    vector<query> queries(q);
    rep(i, 0, q) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--;
        queries[i].r--;
        queries[i].id = i;
    }
    sort(queries.begin(), queries.end(), comp);
    int l = 0, r = -1;
    for(auto &qr : queries) {
        while(l > qr.l) {
            add(--l);
        }
        while(r < qr.r) {
            add(++r);
        }
        while(l < qr.l) {
            rem(l++);
        }
        while(r > qr.r) {
            rem(r--);
        }
        ans[qr.id] = sum;
        l = qr.l, r = qr.r;
    }
    rep(i, 0, q) cout << ans[i] << '\n';
    return 0;
}