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
    vector <ll> v(n);
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] == 1) cnt++;
    }

    if (cnt == n) {
        cout << "Yes" << '\n';
        return;
    }
    
    for (int i = 0; i < n - 1; i++) {
        if (v[i] == v[i + 1] && v[i] == 0) {
            cout << "Yes" << '\n';
            return;
        }
    }
    cout << "No" << '\n';
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