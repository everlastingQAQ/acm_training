#include <bits/stdc++.h>
using namespace std;
using ld = long double;

#define fi first
#define se second
#define int long long

const int MAXN = 6e7;
const double eps = 1e-12;
const int mod = 998244353;

void init() 
{

}

void solve ()
{
    int n, k; cin >> n >> k;
    vector <int> v(n);
    for (int &x : v) cin >> x;
    int ans = 0;
    bool found = false;
    for (int i = 1; i < n; i++) {
        ans += abs(v[i] - v[i - 1]) / k;
        if (ans > 0) found = true;
        if ((v[i] - v[i - 1]) % k == 0 && v[i] - v[i - 1] != 0) ans--;
    }

    cout << (found ? ans : 1) << '\n';
    
}   

signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    init();
    while (_--) {
        solve();
    }
    return 0;
}