#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, k;
    cin >> n >> k;
    vector <i64> v;
    vector <i64> l(n), r(n);
    for (int i = 0; i < n; i++) {
    	cin >> l[i] >> r[i];
    	v.push_back(l[i]);
    	v.push_back(r[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int m = v.size();
    vector <int> d(m + 1);
    for (int i = 0; i < n; i++) {
    	int ll = lower_bound(v.begin(), v.end(), l[i]) - v.begin();
    	int rr = lower_bound(v.begin(), v.end(), r[i]) - v.begin();
    	d[ll]++;
    	d[rr]--;
    }
    i64 ans = 0;
    int cur = 0;
    for (int i = 0; i < m - 1; i++) {
    	cur += d[i];
    	if (cur >= k) ans += v[i + 1] - v[i];
    }
    cout << ans << '\n';
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