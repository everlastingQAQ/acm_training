#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n; cin >> n;
    vector <int> v(n);
    for (int &x : v) {
        cin >> x;
    }
    int mn = ranges::min(v);

    int t = 0;
    int cnt = 0;
    for (int x : v) {
        if (x % mn == 0 && x != mn) t = gcd(t, x);
        if (x == mn) cnt++;
    } 
    
    cout << ((t == mn || cnt > 1) ? "Yes" : "No") << '\n';
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