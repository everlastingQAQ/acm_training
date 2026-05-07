#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	int n;
    i64 p;
    cin >> n >> p;
    vector <i64> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i] %= p;
    }

    i64 ans = 0;
    sort(v.begin() + 1, v.end());
    v.erase(unique(v.begin() + 1, v.end()), v.end());

    for (int i = 1; i < v.size(); i++) {
        i64 t = p - v[i];
        i64 pos = lower_bound(v.begin() + 1, v.end(), t) - v.begin() - 1;
        if (pos == i) pos--;
        if (pos > 0) ans = max(ans, v[i] + v[pos]);
        if (i != v.size() - 1) ans = max(ans, (v[i] + v.back()) % p);
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