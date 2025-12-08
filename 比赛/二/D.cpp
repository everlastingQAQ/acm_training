#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll t;

void solve ()
{
    cin >> t;
    string s;
    
    for (int i = 0; i < t; i++) {
        ll ans = 0;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == 'h' && s[j + 1] == 'y' && s[j + 2] == 'w') {
                ans++;
            }
        }
        cout << ans << '\n';
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