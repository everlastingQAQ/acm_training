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
    vector <ll> d(n + 1);
    vector <ll> tag;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        
    }

    for (int i = 1; i <= n; i++) {
        if (v[i] == -1) {
            if (i == 1) {
                if (v[n] == -1) {
                    v[1] = 0;
                    v[n] = 0;
                }else {
                    v[1] = v[n];
                }
            }else if (i == n) {
                v[n] = v[1];
            }else {
                v[i] = 0;
            }
        }
    }

    ll ans1 = 0;
    for (int i = 1; i <= n; i++) {
        d[i] = v[i] - v[i - 1];
        if (i != 1) {
            ans1 += d[i];
        }
    }

    cout << abs(ans1) << '\n';

    for (int i = 1; i <= n; i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';

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