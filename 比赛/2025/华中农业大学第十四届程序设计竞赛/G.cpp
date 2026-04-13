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

ll m, n, x;

void solve ()
{
    cin >> m >> n;
    vector <ll> a(m);
    vector <ll> b(n);
    vector <ll> c(n);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    cin >> x;

    for (int i = 0; i < n; i++) {
        if (c[i] > m) {
            cout << "No" << '\n';
            return;
        }   
    }

    sort(a.begin(), a.end());

    vector <ll> s(m);
    s[0] = a[0];
    for (int i = 1; i < m; i++) {
        s[i] = s[i - 1] + a[i];
    }

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += s[c[i] - 1] + a[0] * max(0LL, b[i] - c[i]);
    }

    if (sum > x) {
        cout << "No" << '\n';
    }else {
        cout << "Yes" << '\n';
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