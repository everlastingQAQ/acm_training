#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
 	int n, m;
 	cin >> n >> m;
 	vector <int> v(m + 1), cnt(n + 1);
 	for (int i = 1; i <= m; i++) {
 		cin >> v[i];
 		cnt[v[i]]++;
 	}  
 	vector <int> pre(n + 1);
 	for (int i = 1; i <= n; i++) {
 		pre[i] = pre[i - 1] + cnt[i];
 	}

 	i64 ans = 0;
 	for (int i = 1; i < n; i++) {
 		i64 cnt1 = m - pre[i - 1];
 		i64 cnt2 = m - pre[n - i - 1];
 		if (cnt2 > cnt1) swap(cnt1, cnt2);
 		// cout << cnt1 << ' ' << cnt2 << '\n';	
 		ans += max(0LL, (cnt1 - 1) * cnt2);
 	}
 	cout << ans << '\n';
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