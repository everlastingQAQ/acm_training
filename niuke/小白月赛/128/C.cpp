#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, a, b; cin >> n >> a >> b;
    string s;
    int c0 = 0, c1 = 0;
    int t = 0;
    for (int i = 1; i <= n; i++) {
        if (abs(b * (c0 + 1) - a * c1) < abs(b * c0 - a * (c1 + 1))) {
            s.push_back('0');
            c0++;
        }else {
            s.push_back('1');
            c1++;
        }
    }
    cout << s << '\n';
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