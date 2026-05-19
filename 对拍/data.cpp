#include <bits/stdc++.h>
using namespace std;
#define int long long

mt19937_64 rng(random_device{}());

void solve ()
{
    cout << 1 << '\n';
    int n = rng() % 100;
    for (int i = 0; i < n; i++) {
        cout << rng() % 4 + 1;
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