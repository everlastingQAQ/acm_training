#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n; cin >> n;
    if (!(n & 1)) {
        cout << n / 2 << ' ' << n / 2 << '\n';
        return;
    }

    int t = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            cout << n / i << ' ' << n - n / i << '\n';
            return;
        }
    }

    cout << 1 << ' ' << n - 1 << '\n';
}   
    
int32_t main ()
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