#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, k; cin >> n >> k;
    int sum = 0;
    int cnt = 0;
    while (sum < k) {
        sum += n;
        n++;
        cnt++;
    }
    cout << cnt - 1 << '\n';
}   
    
int32_t main ()
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