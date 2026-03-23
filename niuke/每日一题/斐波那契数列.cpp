#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 1e9 + 7;

void solve ()
{
    int n;
    cin >> n;
    vector <i64> v(max(2, n + 1));
    v[1] = 1;
    v[2] = 1;
    for (int i = 3; i <= n; i++) {
        v[i] = v[i - 1] + v[i - 2];
        v[i] %= mod;
    }

    cout << v[n] << '\n';
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