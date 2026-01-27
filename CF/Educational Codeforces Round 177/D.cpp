#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1000000;

void solve ()
{
    int n; cin >> n;
    vector <int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] % b[i] == 0) {
                
        }
    }

    cout << ans << '\n';
}   
    
signed main ()
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