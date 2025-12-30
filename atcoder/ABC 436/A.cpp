#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, char>;

#define fi first
#define se second

const int N = 3e5;
const double eps = 1e-5;
const ll mod = 998244353;

void solve ()
{
    ll n; string s; cin >> n >> s;   
    ll m = s.size();
    for (int i = 0; i < n - s.size(); i++) {
        cout << 'o';
    }
    cout << s;
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}   