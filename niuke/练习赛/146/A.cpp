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

ll n;

void solve ()
{
    cin >> n;
    vector <ll> v(n + 1);
    ll cnt1 = 0;
    ll cnt2 = 0;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        sum += v[i];
        if (v[i] % 2 == 0) {
            cnt1++;
        }else {
            cnt2++;
        }
    }

    ll t = sum / n;
    if (t < 2) {
        ll temp = sum % n;
        cnt2 -= n - temp;
        n -= n - temp;
    }
    //cout << cnt2 << ' ' << n << '\n';

    if (cnt2 % 2 == 1) {
        cout << n - 1 << '\n';
    }else {
        cout << n << '\n';
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