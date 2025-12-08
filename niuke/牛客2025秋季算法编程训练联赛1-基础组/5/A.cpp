#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

ll n, m;
string s1, s2;

void solve ()
{
    cin >> n >> m >> s1 >> s2;

    ll ans = 0;
    ll mn = min(n, m);
    for (int i = 0; i < mn; i++) {
        if (s1[i] != s2[i]) {
            ans++;
        }
    }

    ans += abs(n - m);

    cout << ans << '\n';
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    //cin >> _; 
    while (_--) {
        solve();
    }
    return 0;
}