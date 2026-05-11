#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const int mod = 998244353;

void solve ()
{
    int n, k; cin >> n >> k;
    vector <int> a(n), b(n);
    for (int &x : a) cin >> x, x = min(x % k, k - x % k);
    for (int &x : b) cin >> x, x = min(x % k, k - x % k);

    ranges::sort(a);
    ranges::sort(b);
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            cout << "No" << '\n';
            return;
        }
    }
    cout << "Yes" << '\n';
}   
    
signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}