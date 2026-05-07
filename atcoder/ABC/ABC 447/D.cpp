#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    int ca = 0, cab = 0;
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (s[i] == 'A') {
            ca++;
        }else if (s[i] == 'B') {
            if (ca > 0) {
                cab++;
                ca--;
            }
        }else if (s[i] == 'C') {
            if (cab > 0) {
                cab--;
                ans++;
            }
        }
    }

    cout << ans << '\n';
} 
    
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 