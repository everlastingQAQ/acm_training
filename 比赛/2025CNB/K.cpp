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
    
ll n, k, p;

void solve ()
{
    cin >> n >> k >> p;
    vector <ll> v(n);
    vector <vector <ll> > a(p);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        a[v[i] % p].push_back(v[i]);
    }

    bool found = false;
    ll ans = LLONG_MAX;
    for (int i = 0; i < p; i++) {
        if (a[i].size() < k) continue;
        else found = true;
        sort(a[i].begin(), a[i].end());

        ll mn = 0;
        for (int j = 0; j < k - 1; j++) {
            mn += (a[i][k - 1] - a[i][j]) / p;
        }

        ans = min(ans, mn);
        ll l = 1, r = k;
        while (r < a[i].size()) {
            mn -= (a[i][r - 1] - a[i][l - 1]) / p;
            mn += (a[i][r] - a[i][r - 1]) / p * (k - 1);
            ans = min(mn, ans);
            l++;
            r++;
        } 
    }

    if (!found) {
        cout << "wuwuwu" << '\n';
    }else {
        cout << ans << '\n';
    }
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