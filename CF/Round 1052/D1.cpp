#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int l, r; cin >> l >> r;
    vector <int> ans(r + 1, -1);
    ans[0] = 0;

    for (int i = r; i >= 1; i--) {
        if (ans[i] != -1) continue;
        int cur = 0;

        int wid = 64 - __builtin_clzll(i);
        int mask = (1LL << (wid - 1)) - 1;
        cur = i ^ (mask ^ (1LL << wid - 1));

        ans[i] = cur;
        ans[cur] = i;
    } 

    cout << r * (r + 1) << '\n';
    for (int i = 0; i <= r; i++) {
        cout << ans[i] << " \n"[i == r];
    }
}   
    
int32_t main ()
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