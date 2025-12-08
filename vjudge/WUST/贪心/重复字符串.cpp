#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

ll n;
string s;

void solve ()
{
    cin >> n >> s;

    ll t = s.size();
    
    if (t % n != 0) {
        cout << -1 << '\n';
        return;
    }

    s = ' ' + s;
    ll ans = 0;

    for (int i = 1; i <= t / n; i++) {
        vector <ll> a(26, 0);
        for (int j = i; j <= t; j += t / n) {
            a[s[j] - 'a']++;
        }
        auto it = max_element(a.begin(), a.end());
        ans += n - *it;
        //cout << ans << '\n';
    }

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