#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 x;
    cin >> x;
    if (x & 1) {
        int pos = 0;
        for (int i = 0; i <= 31; i++) {
            if (((x >> i) & 1) == 0) {
                pos = i;
                break;
            }
        }
        cout << (1LL << pos) << '\n';
    }else {
        cout << 1 << '\n';
    }
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