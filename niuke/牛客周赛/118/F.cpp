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
    vector <ll> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    
    ll mx = *max_element(v.begin() + 1, v.end());

    ll cnt = 0;
    for (int x : v) {
        if (x == mx) cnt++;
    }

    if (mx >= cnt) {
        cout << "red" << '\n';
    }else {
        cout << "purple" << '\n';
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