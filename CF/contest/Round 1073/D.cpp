#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int n; cin >> n;
    string s; cin >> s; s = ' ' + s;
    for (int i = 1; i <= n; i++) {
        if (s[i] == ')') {
            int cnt = count(s.begin() + i + 1, s.end(), ')');
            if (cnt >= i) {
                cout << n - 2 << '\n';
            }else {
                cout << -1 << '\n';
            }
            return;
        }
    }

}   
    
signed main ()
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