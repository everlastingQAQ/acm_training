#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

int C[35][35];

void init ()
{
    for (int i = 0; i <= 34; i++) {
        C[i][0] = 1, C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
}

void solve ()
{
    int n, k; cin >> n >> k;
    int cnt = bit_width((unsigned)n) - 1;

    int ans = 0;
    for (int i = 1; i <= cnt; i++) {
        for (int j = 1; j <= i; j++) {
            if (i + j - 1 <= k) continue;
            ans += C[i - 1][j - 1];
        }
    }

    if (cnt + 1 > k) ans++;
    cout << ans << '\n'; 
}   
    
signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    init();
    while (_--) {
        solve();
    }
    return 0;
}