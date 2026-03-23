#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int a, b, d, e;
    cin >> a >> b >> d >> e;
    int ans = 0;
    for (int i = -101; i <= 101; i++) {
        int cnt = 0;
        int c = i;
        if (c == a + b) cnt++;
        if (d == b + c) cnt++;
        if (e == c + d) cnt++;
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
} 
    
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 