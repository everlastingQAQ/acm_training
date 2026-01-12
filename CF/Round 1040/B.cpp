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
    int n, s; cin >> n >> s;
    vector <int> v(n + 1);
    vector <int> cnt(3);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        cnt[v[i]]++;
    }
    if (accumulate(v.begin() + 1, v.end(), 0LL) > s || accumulate(v.begin() + 1, v.end(), 0LL) + 1 == s) {
        for (int i = 0; i < cnt[0]; i++) {
            cout << 0 << ' ';
        }
        for (int i = 0; i < cnt[2]; i++) {
            cout << 2 << ' ';
        }
        for (int i = 0; i < cnt[1]; i++) {
            cout << 1 << " \n"[i == cnt[1] - 1];
        }
    }else {
        cout << -1 << '\n';
    }
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