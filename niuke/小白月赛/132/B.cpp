#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(6);
    vector <int> ans(6);
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        int t;
        cin >> t;
        if (t > v[c - 'A']) {
            ans[c - 'A'] = i;
            v[c - 'A'] = t;
        }
    }
    bool ok1 = true, ok2 = true;
    int sum = 0;
    for (auto x : v) {
        sum += x;
        if (x < 60) ok1 = false;
    }
    if (sum < 70 * 6) ok2 = false;
    if (!ok1 || !ok2) {
        cout << -1 << '\n';
        return;
    }
    for (auto x : ans) {
        cout << x << ' ';
    }
}   

int32_t main ()
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