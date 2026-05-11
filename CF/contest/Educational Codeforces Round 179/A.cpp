#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{   
    int n;
    cin >> n;
    vector <int> v(3);
    int cnt = 0;
    while (v[0] < n) {
        v[0] = v[1] * 2 + 1;
        ranges::sort(v);
        cnt++;
    }
    cout << cnt << '\n';
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