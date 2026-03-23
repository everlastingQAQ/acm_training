#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int m;
    cin >> m;
    if (m == 2) {
        cout << 3 << '\n';
        return;
    }else if (m == 3) {
        cout << 8 << '\n';
        return;
    }
    i64 a = 1, b = 1, c = 2;
    int cnt = 1;
    for (int i = 5; i <= m * m; i++) {
        if (a % m == 0 && b % m == 1) {
            cout << cnt << '\n';
            return;
        }
        i64 t = c;
        i64 t1 = b;
        c += b;
        b = t;
        a = t1;
        a %= m;
        b %= m;
        c %= m;
        cnt++;
    }
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