#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 998244353;
 
ll n;
string s;

void solve ()
{
    cin >> n >> s;
    ll cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] != s[i + 1]) {
            cnt++;
        }
    }
    if (cnt > 2) {
        if (s[0] == '1') {
            cout << n + cnt - 1 << '\n';
        }else {
            cout << n + cnt - 2 << '\n';
        }
    }else {
        if (cnt == 0) {
            if (s[0] == '1') {
                cout << n + 1 << '\n';
            }else {
                cout << n << '\n';
            }
        }else if (cnt == 1) {
            cout << n + 1 << '\n';
        }else if (cnt == 2) {
            cout << n + 1 << '\n';
        }
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