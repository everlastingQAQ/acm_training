#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    cout << "a";
    int d = n - (2 * (n - 2) - m) - 2;
    cout << string(d, 'b');
    int x = 0;
    for (int i = 0; i <= 2 * (n - 2) - m; i++) {
        char c = 'c' + x;
        cout << c;
        x++;
        if (x == 24) x = 0;
    }
    cout << '\n';
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