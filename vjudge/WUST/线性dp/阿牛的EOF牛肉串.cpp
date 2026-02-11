#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
int f[41];

void init ()
{
    f[1] = 3, f[2] = 8;
    for (int i = 3; i < 40; i++) {
        f[i] = 2 * f[i - 1] + 2 * f[i - 2];
    }
}

void solve ()
{
    
}   
    
int32_t main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // int _ = 1;
    // cin >> _;
    // while (_--) {
    //     solve();
    // }
    init();
    while (cin >> n) {
        cout << f[n] << '\n';
    }
    return 0;
} 