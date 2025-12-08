#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n;

void solve ()
{
    cin >> n;
    vector <ll> b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    vector <ll> a(n + 1);
    a[1] = 1;

    for (int i = 2; i <= n; i++) {
        ll t = b[i] - b[i - 1];
        if (t == i) {
            a[i] = i;
        }else {
            a[i] = a[i - t];
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
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