#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;

ll n, k;
string s;

void solve ()
{
    cin >> n >> k >> s;
    map<string, ll> mp;
    s = ' ' + s;
    ll ans2 = 0;

    ll l = 1, r = k;

    for (int i = 1; i <= n - k + 1; i++) {
        string sub = s.substr(i, k);
        mp[sub]++;
        ans2 = max(ans2, mp[sub]);
    }

    l = 1, r = k;
    set <string> ans1;
    for (int i = 1; i <= n - k + 1; i++) {
        string sub = s.substr(i, k);
        if (mp[sub] == ans2) {
            ans1.insert(sub);
        }
    }

    cout << ans2 << '\n';
    for (auto x : ans1) {
        cout << x << ' ';
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