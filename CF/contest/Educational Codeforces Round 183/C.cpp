#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 998244353;
        
ll n;
string s;

void solve ()
{
    cin >> n >> s;
    s = " " + s;
    vector <ll> a(n + 1);
    vector <ll> b(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + (s[i] == 'a');
        b[i] = b[i - 1] + (s[i] == 'b');
    }

    if (a[n] == b[n]) {
        cout << 0 << '\n';
        return;
    }else if (a[n] < b[n]) {
        swap(a, b);
    }

    vector <ll> d(n + 1);
    for (int i = 1; i <= n; i++) {
        d[i] = a[i] - b[i];
    }
    
    ll t = a[n] - b[n];
    ll ans = n;
    map <ll, ll> mp;
    mp[0] = 0;

    for (int i = 1; i <= n; i++) {
        if (mp.count(d[i] - t)) {
            ans = min(ans, i - mp[d[i] - t]);
        }
        mp[d[i]] = i;
    }
    
    if (ans == n) {
        cout << -1 << '\n';
    }else {
        cout << ans << '\n';
    }
} 
 
int main ()
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