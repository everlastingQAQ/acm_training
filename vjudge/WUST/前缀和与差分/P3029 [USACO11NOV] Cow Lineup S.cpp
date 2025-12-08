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
    vector <pi> v(n);
    set <ll> st;
    for (int i = 0; i < n; i++) {
        cin >> v[i].fi >> v[i].se;
        st.insert(v[i].se);
    }
    sort(v.begin(), v.end(), [] (auto &a1, auto &b1) {
        return a1.fi < b1.fi;
    });

    // for (auto [x, y] : v) {
    //     cout << x << ' ' << y << '\n';
    // }

    ll l = 0, r = 0;
    ll t = st.size();
    map <ll, ll> mp;
    ll cnt = 0;
    ll ans = LLONG_MAX;

    while (r < n) {
        if (!mp[v[r].se]) {
            cnt++;
        }
        mp[v[r].se]++;
        r++;
        while (l < r && cnt == t) {
            ans = min(ans, v[r - 1].fi - v[l].fi);
            mp[v[l].se]--;
            if (mp[v[l].se] == 0) {
                cnt--;
            }
            l++;
        }
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