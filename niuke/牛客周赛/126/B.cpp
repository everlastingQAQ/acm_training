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
    vector <string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), [] (const string s1, const string s2) {
        if (s1.size() != s2.size()) return s1.size() < s2.size();
        else return s1 < s2;
    });
    
    if (v[k] == v[k - 1]) {
        cout << -1 << '\n';
    }else {
        cout << v[k - 1] << '\n';
    }

}   

signed main ()
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