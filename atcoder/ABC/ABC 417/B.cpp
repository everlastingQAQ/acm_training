#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;

void solve ()
{   
    ll n, m; cin >> n >> m;
    vector <ll> a(n), b(m);
    map <ll, ll> mp;
    for (ll &x : a) cin >> x, mp[x]++;
    for (ll &x : b) cin >> x, mp[x]--;
    vector <ll> ans;
    for (int i = 0; i < n; i++) {
        while (mp[a[i]] > 0) {
            ans.push_back(a[i]);
            mp[a[i]]--;
        }
    }
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
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