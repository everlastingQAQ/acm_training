#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
string s;

void solve ()
{
    cin >> s;
    ll n = s.size();
    ll l = 0, r = s.size() - 1;

    ll ans[n];
    while (l <= r) {
        if (s[l] != s[r]) {
            ll a, b;
            a = max(s[l], s[r]);
            b = min(s[l], s[r]);
            if (s[l] == a) {
                ans[l] = 0;
                ans[r] = a - b;
            }else {
                ans[l] = a - b;
                ans[r] = 0;
            }
        }else {
            ans[l] = 0;
            ans[r] = 0;
        }   
        l++;
        r--;
    }

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (ans[i] != 0) {
            found = true;
        }
        if (!found && ans[i] == 0) {
            continue;
        }
        cout << ans[i];
    }

    if (!found) {
        cout << 0 << '\n';
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