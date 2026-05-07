#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int h, w, q;
    cin >> h >> w >> q;
    while (q--) {
        int op, t;
        cin >> op >> t;
        if (op == 1) {
            cout << t * w << '\n';
            h -= t;
        }else {
            cout << t * h << '\n';
            w -= t;
        }
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
