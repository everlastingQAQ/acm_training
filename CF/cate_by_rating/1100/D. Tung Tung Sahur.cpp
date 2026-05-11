#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 998244353;
    
string s1, s2;

void solve ()
{   
    cin >> s1 >> s2;
    ll n = s1.size(), m = s2.size();
    if (n > m || n * 2 < m) {
        cout << "No" << '\n';
        return;
    }

    ll l = 0, r = 0;
    while (r < m) {
        ll tl = l;
        while (l < n && s1[l] == s1[l + 1]) {
            l++;
        }
        if (s2[r] != s1[l]) {
            cout << "No" << '\n';
            return;
        }
        ll tr = r;
        while (s2[r] == s2[r + 1]) {
            r++;
        }
        if (r - tr + 1 < l - tl + 1 || r - tr + 1 > 2 * (l - tl + 1)) {
            cout << "No" << '\n';
            return;
        }
        l++;
        r++;
    }

    if (s1[l] != s2[r]) {
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