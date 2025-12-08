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
    vector <pair<ll, ll> > v(n);
    vector <ll> cnt(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i].fi >> v[i].se;
        cnt[v[i].fi]++;
        cnt[v[i].se]++;
    }

    vector <pair<ll, ll> > a;
    ll count = 0;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] > 2) {
            a.push_back({i, cnt[i]});
            sum += cnt[i];
            count++;
        }
    }

    sum -= count * 2;

    if (sum <= 0) {
        cout << 0 << '\n';
    }else {
        cout << sum << '\n';
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