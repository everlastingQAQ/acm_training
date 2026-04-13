#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 1e9 + 7;

ll n;

void solve ()   
{
    cin >> n;
    vector <ll> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    vector <ll> s(n + 1, 0);
    vector <ll> ss(n + 1, 0);

    if (v[1] > 0) {
        s[1] = v[1];
    }else {
        s[1] = 0;
    }

    for (int i = 2; i <= n; i++) {
        if (v[i] > 0) {
            s[i] = s[i - 1] + v[i];
        }else {
            s[i] = s[i - 1];
        }
    }

    if (v[n] < 0) {
        ss[n] = abs(v[n]);
    }else {
        ss[n] = 0;
    }

    for (int i = n - 1; i >= 1; i--) {
        if (v[i] < 0) {
            ss[i] = ss[i + 1] + abs(v[i]);
        }else {
            ss[i] = ss[i + 1];
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, s[i] + ss[i]);
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