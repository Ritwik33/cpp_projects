#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

class query {
public:
	int l, r, id;
};

int a[200000], ans[200000], n, q, sum;
const int b = sqrt(200000);

void add(int i)
{
	sum += a[i];
}

void rem(int i)
{
	sum -= a[i];
}

bool cmp(query q1, query q2)
{
	return q1.l / b < q2.l / b or (q1.l / b == q2.l / b and q1.r < q2.r);
}

int32_t main()
{
	FIO;
	cin >> n >> q;

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	vector<query> queries(q);
	for (int i = 0; i < q; ++i)
	{
		cin >> queries[i].l >> queries[i].r;
		queries[i].l--;
		queries[i].r--;
		queries[i].id = i;
	}

	sort(queries.begin(), queries.end(), cmp);

	int l = 0, r = -1;

	for (query &qr : queries)
	{
		while (l > qr.l) // add from left
			add(--l);

		while (r < qr.r) // add from right
			add(++r);

		while (l < qr.l) // rem from left
			rem(l++);

		while (r > qr.r) // rem from right
			rem(r--);

		ans[qr.id] = sum;
		l = qr.l, r = qr.r;
	}

	for (int i = 0; i < q; ++i)
		cout << ans[i] << '\n';


	return 0;
}