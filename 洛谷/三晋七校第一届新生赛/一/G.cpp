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
    ll sum = 0;
    ll a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        sum += a;
    }

    if (sum % n == 0) {
        cout << "Yes" << '\n';
    }else {
        cout << "No" << '\n';
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