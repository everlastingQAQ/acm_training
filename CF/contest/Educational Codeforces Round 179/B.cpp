#include <bits/stdc++.h>
using namespace std;
#define int long long

vector <int> f(11);

void init ()
{
    f[1] = 1, f[2] = 2;
    for (int i = 3; i <= 10; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
}

void solve ()
{   
    int n, m;
    cin >> n >> m;
    int mn = f[n];
    int mx = f[n] + f[n - 1];
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        if (min({a, b, c}) < mn || max({a, b, c}) < mx) {
            cout << 0;
        }else {
            cout << 1;
        }
    }
    cout << '\n';
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