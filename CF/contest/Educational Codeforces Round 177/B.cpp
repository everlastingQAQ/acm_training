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
    ll n, k, x; cin >> n >> k >> x;
    vector <ll> v(n + 1);
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    if (sum < x) {
        ll t = x / sum;
        ll temp = x - sum * t;
        if (temp == 0 && t == k) {
            cout << 1 << '\n';
            return;
        }else if (t == k && temp != 0 || t > k) {
            cout << 0 << '\n';
            return;
        }else {
            ll cur = 0, pos = 0;
            for (int i = n; i >= 1; i--) {
                cur += v[i];
                if (cur >= temp) {
                    break;
                }
                pos++;
            }
            // cout << cur << ' ' << temp << '\n';
            if (0 == temp) cout << max(0LL, k * n - t * n - pos + 1) << '\n';
            else cout << max(0LL, k * n - t * n - pos) << '\n';
        }
    }else {
        ll cur = 0, pos = 0;
        for (int i = n; i >= 1; i--) {
            cur += v[i];
            if (cur >= x) {
                break;
            }
            pos++;
        }
        cout << max(0LL, k * n - pos) << '\n';
    }

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