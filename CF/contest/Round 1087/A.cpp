#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 n, c, k;
    cin >> n >> c >> k;
    vector <i64> v(n + 1);
    for (int i = 1; i <= n; i++) {
    	cin >> v[i];
    }
    sort(v.begin() + 1, v.end());

    i64 cur = c;
    for (int i = 1; i <= n; i++) {
    	if (v[i] > cur) break;
    	if (v[i] <= cur) {
    		if (k <= 0) {
    			cur += v[i];
    		}else if (cur - v[i] <= k) {
    			k -= cur - v[i];
    			cur *= 2;
    		}else {
    			v[i] += k;
    			k = 0;
    			cur += v[i];
    		}
    	}
    }

    cout << cur << '\n';
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