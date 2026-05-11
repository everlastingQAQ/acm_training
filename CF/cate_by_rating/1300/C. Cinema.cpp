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

void solve ()
{
    cin >> n;
    vector <ll> a(n + 1);
    map <ll, ll> mp;
    ll mx = 0;
    vector <ll> ans;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]]++;
        mx = max(mp[a[i]], mx);
    }

    cin >> m;
    vector <ll> b(m + 1);
    vector <ll> c(m + 1);

    vector <ll> ans1;
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        if (mp[b[i]] == mx) {
            ans1.push_back(i);
        }
    }

    if (ans1.size() == 1) {
        cout << ans[0] << '\n';
        return;
    }
    
    for (int i = 1; i <= m; i++) {
        cin >> c[i];
    }

    for ()

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