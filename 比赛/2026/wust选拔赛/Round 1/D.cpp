#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int x, d;
    cin >> x >> d;
    vector <int> v;
    int n = (1LL << 32);
    int sum = 0;
    int t = 32;
    while (x > 0) {
        while (n - 1 <= x) {
            x -= n - 1;
            v.push_back(t);
            sum += t;
        }
        n >>= 1;
        t--;
    }
    
    cout << sum << '\n';
    int cur = 1;
    for (auto cnt : v) {
        for (int i = 0; i < cnt; i++) {
            cout << cur << ' ';
        }
        cur += d + 1;
    }
}

int32_t main ()
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