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

    if (n == 1) {
        cout << 1 << ' ' << 1 << '\n';
        return;
    }

    vector <ll> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        a[v[i]]++;
    }

    ll mx = 0, l = 1, r = 1;
    ll ansl = 1, ansr = 1;

    while (r <= n) {
        if (a[v[r]] == 1) {
            r++;
        }else {
            if ((r - 1) - l + 1 > mx) {
                mx = (r - 1) - l + 1;
                ansl = l;
                ansr = r - 1;
            }
            r++;
            l = r;
        }
    }
    
    if (a[v[n]] == 1) {
        if ((r - 1) - l + 1 > mx) {
            mx = (r - 1) - l + 1;
            ansl = l;
            ansr = r - 1;
        }
    }

    if (mx == 0) {
        cout << 0 << '\n';
    }else {
        cout << ansl << ' ' << ansr << '\n';
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