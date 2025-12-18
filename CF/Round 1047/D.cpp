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

void solve ()
{   
    cin >> n;
    vector <ll> v(n + 1);
    map <ll, ll> mp;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }
    for (auto [x, y] : mp) {
        if (x > y || y % x != 0) {
            cout << -1 << '\n';
            return;
        }
    }

    vector <ll> ans(n + 1);
    vector <vector <ll> > a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[v[i]].push_back(i);
    }
    
    ll t = 1;
    for (int i = 1; i <= n; i++) {
        ll cnt = 0;
        for (auto x : a[i]) {
            ans[x] = t;
            cnt++;
            if (cnt >= i) {
                t++;
                cnt = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    
    cout << '\n';
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