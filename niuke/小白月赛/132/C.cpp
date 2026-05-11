#include <bits/stdc++.h>
using namespace std;
#define int long long

vector <int> v;

void init () {
    v.reserve(4000);
    int a = 1;
    for (int i = 1; i <= 63; i++) {
        int b = 1;
        for (int j = 1; j <= 63; j++) {
            int t = a + b;
            v.push_back(t);
            b *= 2;
        }
        a *= 2;
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}

void solve ()
{
    int l, r;
    cin >> l >> r;
    int pl = lower_bound(v.begin(), v.end(), l) - v.begin();
    int pr = upper_bound(v.begin(), v.end(), r) - v.begin() - 1;
    int ans = pr - pl + 1;
    cout << ans << '\n';
}   

int32_t main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    init();
    while (_--) {
        solve();
    }
    return 0;
}   