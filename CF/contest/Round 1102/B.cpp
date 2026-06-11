#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    for (int i = 0; i <= 11; i++) {
        if (i == 10) continue;
        if (n >= i && (n - i) % 12 == 0) {
            cout << i << ' ' << n - i << '\n';
            return;
        }
    }
    if (n >= 22 && n % 12 == 10) {
        cout << 22 << ' ' << n - 22 << '\n';
        return;
    } 
    cout << -1 << '\n';
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