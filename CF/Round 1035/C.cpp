#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 n, l, r, k;
    cin >> n >> l >> r >> k;
    if (n & 1) {
        cout << l << '\n';
        return;
    }

    i64 t = 1;
    while (t <= l) {
        t <<= 1LL;
    }

    if (t > r || n == 2) {
        cout << "-1\n";
        return;
    }

    if (k == n || k == n - 1) {
        cout << t << '\n';
    }else {
        cout << l << '\n';
    }
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