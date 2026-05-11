#include <bits/stdc++.h>
using namespace std;

void solve ()
{
    int a, b;
    cin >> a >> b;
    int ans = b - a;
    int cnt = 0;
    for (int i = a; i < b; i++) {
        int t = i | b;
        int cur = cnt + 1 + t - b;
        ans = min(ans, cur);
        cnt++;
    }
    int t = b;
    int c = 1;
    while ((t | a) != t) {
        c++;
        t++;
    }
    ans = min(ans, c);

    cout << ans << '\n';
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