#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int x, n, m;
    cin >> x >> n >> m;
    auto cal1 = [&] (int x, int cnt) -> int {
        while (cnt--) {
            if (x & 1) x++;
            x >>= 1;
            if (x <= 1) return x;
        }
        return x;
    };
    auto cal2 = [&] (int x, int cnt) -> int {
        while (cnt--) {
            x >>= 1;
            if (x == 0) return 0;
        }
        return x;
    };

    cout << cal2(cal1(x, m), n) << ' ' << cal1(cal2(x, n), m) << '\n';
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