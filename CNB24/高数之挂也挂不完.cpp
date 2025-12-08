#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n, k;

void solve ()
{
    cin >> n >> k;

    vector<ll> a(n + 1);
    ll t = 1;
    
    for (int i = 1; i <= k; i++) {
        for (int j = i; j <= n; j += k) {
            a[j] = t;
            t++;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
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