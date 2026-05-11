#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, s;
    cin >> n >> s;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        if (x == s / 2 && y == s / 2) {
            ans++;
        }else if (x == y) {
            if ((a == 1 && b == 1) || (a == -1 && b == -1)) {
                ans++;
            }
        }else if (x + y == s) {
            if ((a == 1 && b == -1) || (a == -1 && b == 1)) {
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
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}