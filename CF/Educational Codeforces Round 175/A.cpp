#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 n;
    cin >> n;
    if (n == 0) {
        cout << 1 << '\n';
        return;
    }else if (n == 1) {
        cout << 2 << '\n';
        return;
    }else if (n == 3) {
        cout << 3 << '\n';
        return;
    }

    i64 ans = 3;
    i64 t = n / 15;
    i64 p = n % 15;
    ans += (t - 1) * 3;
    ans += min(p + 1, 3LL);

    cout << ans << '\n';
}   
    
int main ()
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