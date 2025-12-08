#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n, q;

void solve ()
{
    cin >> n >> q;
    ll mxx = 0;
    ll mnn = 1e9 + 1;

    vector <ll> v(n + 1);
    unordered_map<ll , pair<ll, ll>> mp;

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        mxx = max(v[i], mxx);
        mnn = min(v[i], mnn);
        mp[v[i]] = {1, i};
    }

    ll x;
    vector <pair<bool, ll> > judge(2 * n + 1, {false, 0});
    while (q--) {
        cin >> x;
        if (x > mxx * 2 || x < mnn * 2) {
            cout << 0 << '\n';
            continue;
        }
        if (judge[x].fi == true) {
            cout << judge[x].se << '\n';
            continue;
        }
        vector <ll> a(n);
        ll mx = 0;
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            if (mp[x - v[i]].fi == 1) {
                ll o;
                if (i > mp[x - v[i]].se) {
                    o = (i - mp[x - v[i]].se) % n;
                }else {
                    o = (i + n - mp[x - v[i]].se) % n;
                }
                a[o]++;
                if (a[o] > mx) {
                    ans = o;
                    mx = a[o];
                }else if (a[o] == mx) {
                    if (o < ans) {
                        ans = o;
                    }
                }
            }
        }
        judge[x].fi = true;
        judge[x].se = ans;
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