#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int q; cin >> q;
    int cur = 0;
    bool ok = false;
    for (int i = 1; i <= q; i++) {
        int op; cin >> op;
        if (op == 1) cur++;
        else if (op == 2) {
            if (cur >= 1) cur--;
        }else if (op == 3) {
            if (!ok) ok = true;
            else ok = false;
        }
        if (ok && cur >= 3) {
            cout << "Yes" << '\n';
        }else {
            cout << "No" << '\n';
        }
    }
}   
    
signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}