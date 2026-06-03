#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (b == 0) {
        if (a) cout << string(a + 1, '0');
        else cout << string(c + 1, '1');
    }else { 
        cout << string(a + 1, '0');
        cout << string(c + 1, '1');
        for (int i = 2; i <= b; i++) {
            cout << (i & 1 ? '1' : '0');
        }
    }
    cout << '\n';
}

int32_t main ()
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
