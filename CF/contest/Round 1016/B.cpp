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

void solve ()
{   
    string s; cin >> s;
    ll cnt_0 = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') cnt_0++;
    }
    ll t = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '0') t++;
        else break;
    }
    cout << (ll)s.size() - 1 - (cnt_0 - t) << '\n';
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