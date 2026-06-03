#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    sort(v.begin() + 1, v.end());
    int sum = 0;
    int mn = 1e18;
    for (int i = 1; i <= n; i++) {
        if (v[i] <= 0) {
            sum++;
            if (i > 1) mn = min(mn, v[i] - v[i - 1]); 
        }
        else {
            // cout << mn << '\n';
            if (i == 1 || v[i] <= mn) sum++;
            break;
        }
    }
    cout << sum << '\n';
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