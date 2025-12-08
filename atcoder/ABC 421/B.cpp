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
const ll inf = LLONG_MAX;

ll x, y;

void solve ()
{
    vector <ll> a(10 + 1);
    cin >> a[1] >> a[2];

    for (int i = 3; i <= 10; i++) {
        ll t = a[i - 1] + a[i - 2];
        string s = to_string(t);
        reverse(s.begin(), s.end());
        a[i] = stoll(s);
    }

    cout << a[10] << '\n';
    
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