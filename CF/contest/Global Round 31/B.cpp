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
    ll n; cin >> n;
    vector <string> v(n);
    for (string &x : v) cin >> x;

    string ans = v[0];
    for (int i = 1; i < n; i++) {
        ll l = 0, r = 0;
        if (ans == v[i]) {
            ans = v[i] + ans;
            continue;
        }
        string t1 = ans + v[i];
        string t2 = v[i] + ans;
        while (l < t1.size() && r < t2.size() && t1[l] == t2[r]) {
            l++;
            r++;
        }
        if (t1[l] < t2[r]) {
            ans = ans + v[i];
        }else {
            ans = v[i] + ans;
        }
    }

    cout << ans << '\n';

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