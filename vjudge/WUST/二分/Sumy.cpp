#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n;

void solve ()
{
    cin >> n;
    vector <ll> v(n);
    map <ll, ll> mp;
    ll mx = 0;
    ll mn = 1e9;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
        mx = max(mx, v[i]);
        mn = min(mn, v[i]);
        mp[v[i]]++;
    }

    vector <bool> vp(mx + 5, false);
    vp[mx] = true;
    for (auto it = mp.rbegin(); it != mp.rend(); it++) {
        if (it == mp.rbegin()) {
            sum -= it->fi * it->se;
            continue;
        }

        auto nxt = prev(it);
        if (it->fi == mn) {
            break;
        }

        if (sum > nxt->fi) {
            vp[it->fi] = true;
        }else {
            break;
        }
        sum -= it->fi * it->se;
    }
    vp[mn] = false;

    if (mx == mn && mp[mn] == 1) {
        vp[mn] = true;
    }

    for (auto &i : v) {
        if (!vp[i]) {
            cout << 'N';
        }else {
            cout << 'T';
        }
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