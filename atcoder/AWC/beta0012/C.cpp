#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, k, m;
    cin >> n >> k >> m;
    vector <i64> a, b;
    for (int i = 0; i < n; i++) {
        int op, val;
        cin >> op >> val;
        if (op == 0) {
            a.push_back(val);
        }else {
            b.push_back(val);
        }
    }

    ranges::sort(a, greater<>());
    ranges::sort(b, greater<>());

    i64 ans = 0;
    if (a.size() < k - m || b.size() < m) {
        cout << -1 << '\n';
        return;
    }

    for (int i = 0; i < k - m; i++) {
        ans += a[i];
    }
    for (int i = 0; i < m; i++) {
        ans += b[i];
    }
    cout << ans << '\n';    
}   
    
int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 