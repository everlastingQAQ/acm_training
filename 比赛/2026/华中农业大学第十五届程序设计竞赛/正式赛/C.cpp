#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const ll MAXN = 1e8;
const ld eps = 1e-12;
const ll mod = 1e9 + 7;

ll n;

void solve ()
{
	cin >> n;
	vector <ll> v(n + 1);
	bool vis = false;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		if (v[i] != 0) {
			vis = true;
		}
	}
//	
//	if (!vis) {
//		for (int i = 1; i <= n; i++) {
//			cout << 0 << ' ';
//		}
//		cout << '\n';
//		return;
//	}
	
	vector <ll> ans(n + 1, 0);
	
	stack <ll> stk;
	
	for (int i = 1; i <= n; i++) {
//		if (!vis[i]) continue;
		while (!stk.empty() && v[i] > stk.top()) {
			stk.pop();
		}
		stk.push(v[i]);
		ans[i] += stk.size();
	}
	
	stack <ll> stk1;
	
	for (int i = n; i >= 1; i--) {
//		if (!vis[i]) continue;
		while (!stk1.empty() && v[i] > stk1.top()) {
			stk1.pop();
		}
		stk1.push(v[i]);
		ans[i] += stk1.size();
	}
	
	for (int i = 1; i <= n; i++) {
//		if (vis[i]) {
//			if (v[i] == 0) {
//				cout << ans[i] - 2 << ' ';
//			}else {
				cout << ans[i] - 1 << ' ';
//			}
//		}else {
//			cout << 1 << ' ';
//		}
//		cout << max(0LL, ans[i] - 1) << ' ';
	}
	cout << '\n';
	
}

int main ()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int _ = 1;
	cin >> _;
	while (_--) {
		solve();
	}
	return 0;
}