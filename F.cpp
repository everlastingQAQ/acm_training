#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	int n;
	cin >> n;
	vector <vector <int> > e(n + 1);
	vector <int> ind(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		ind[u]++;
		ind[v]++;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	int x;
	cin >> x;

	if (ind[x] == 1) {
		cout << "xiaonian wins!";
		return;
	}else {
		if (n & 1) {
			cout << "coldtree wins!";
		}else {
			cout << "xiaonian wins!";
		}
	}
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 
