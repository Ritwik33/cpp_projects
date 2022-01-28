#include<bits/stdc++.h>
using namespace std;

#define endl                                                       '\n'
#define inf                                                        1e18
#define mod                                                        1000000007
#define int                                                        long long
#define vi                                                         vector<int>
#define vvi                                                        vector<vector<int>>
#define pb(x)                                                      push_back(x)
#define ppb                                                        pop_back()
#define rep(i, a, b)                                               for(int i = a;i<b;i++)
#define repd(i, a)                                                 for(int i = a;i>=0;i--)
#define setbits(x)                                                 __builtin_popcountll(x)
#define ps(x, y)                                                   fixed << setprecision(y) << x
#define w(q)                                                       int q; cin >> q; while(q--)
#define FIO                                                        ios_base::sync_with_stdio(false); cin.tie(NULL);

vector<char> word;

class node {
public:
	int pre, ends, num;
	unordered_map<char, node*> child;
	node() {
		pre = ends = num = 0;
		child = {};
	}
};

class trie {
public:
	node *root;
	trie() {
		root = new node();
	}

	void insert(const string& word) {
		node *cur = root;
		for (char letter : word) {
			cur -> pre++;
			if (cur -> child[letter] == NULL) cur -> child[letter] = new node();
			cur = cur -> child[letter];
		}
		cur -> pre++, cur -> ends++, cur -> num++;
	}

	int occurences(const string& word) {
		node *cur = root;
		for (char letter : word) {
			if ((cur -> child).count(letter) == 0) return 0;
			cur = cur -> child[letter];
		}
		return cur -> ends;
	}

	int startsWith(const string& prefix) {
		node *cur = root;
		for (char letter : prefix) {
			if ((cur -> child).count(letter) == 0) return 0;
			cur = cur -> child[letter];
		}
		return cur -> pre;
	}

	bool del(const string& word) {
		node *cur = root;
		if (occurences(word) == 0) return false;
		for (char letter : word) {
			cur -> pre--;
			cur = cur -> child[letter];
		}
		cur -> pre--, cur -> ends--, cur -> num--;
		return true;
	}

	node *del_aux(node *cur, const string& word, int i) {
		cur -> pre--;
		int n = word.length();
		if (i == n - 1) {
			cur -> ends--, cur -> num--;
		} else {
			cur -> child[word[i + 1]] = del_aux(cur -> child[word[i + 1]], word, i + 1);
			if (cur -> child[word[i + 1]] == NULL) (cur -> child).erase(word[i + 1]);
		}
		if (cur -> pre) {
			return cur;
		}
		delete cur;
		return NULL;
	}

	bool del_actual(const string& word) {
		if (occurences(word) == 0) return false;
		root -> child[word[0]] = del_aux(root -> child[word[0]], word, 0);
		return true;
	}

	void printTrie(node *cur) {
		if (cur -> ends == 1 and cur -> pre == 1) {
			for (char ch : word) cout << ch;
			cout << endl;
			cur -> num--;
			return;
		}
		for (auto it : (cur -> child)) {
			word.push_back(it.first);
			printTrie(it.second);
			word.pop_back();
			if (cur -> num >= 1) {
				while (cur -> num--) {
					for (char ch : word) cout << ch;
					cout << endl;
				}
			}
		}
	}
};

void solve() {
	trie t;
	t.insert("the");
	t.insert("a");
	t.insert("there");
	t.insert("answer");
	t.insert("any");
	t.insert("bye");
	t.insert("by");
	t.insert("their");
	t.printTrie(t.root);
}

int32_t main() {
	FIO;

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}