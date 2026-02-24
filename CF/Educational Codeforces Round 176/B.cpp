#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, k;
    cin >> n >> k;
    vector <int> v(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    if (k != 1) {
        sort(v.begin() + 1, v.begin() + 1 + n, greater<int>());
        int ans = accumulate(v.begin() + 1, v.begin() + 1 + k + 1, 0LL);
        cout << ans << '\n';
    }else {
        int ans = v[1] + v[n];
        for (int i = 2; i <= n - 1; i++) {
            ans = max(ans, v[i] + max(v[1], v[n]));
        }
        cout << ans << '\n'; 
    }
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

/*
  /\_/\
 (= ._.)
 / >  \>
*/