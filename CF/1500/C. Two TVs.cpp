#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

ll n;

void solve ()
{
    cin >> n;
    vector <ll> a(n);
    vector <ll> b(n);

    ll mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        b[i]++;
        mx = max(mx, b[i]);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll t = 0;
    ll l = 0, r = 0;

    for (int i = 0; i <= mx; i++) {
        while (l < n && i == a[l]) {
            t++;
            l++;
        }
        while (r < n && i == b[r]) {
            t--;
            r++;
        }
        if (t > 2) {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';

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