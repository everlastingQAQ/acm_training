#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	int n;
	cin >> n;
	vector <int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}    

	vector <int> ans(n + 1, -1);
	
	map <int, int> mp;
	int cur = 1;
	for (int i = 1; i <= n; i++) {
		if (!mp.count(v[i])) {
			mp[v[i]] = cur;
			cur++;
		}
		ans[i] = mp[v[i]];
	}

	for (int i = 1; i <= n; i++) {
	    cout << ans[i] << " \n"[i == n];
	}
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 