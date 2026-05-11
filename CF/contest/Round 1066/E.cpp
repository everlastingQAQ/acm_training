#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, k;
    cin >> n >> k;
    vector <int> v(n + 1);
    vector <int> cnt(3 * n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        cnt[v[i]]++;
    }
    int ans = 0, sum = 0, t = 0;
    for (int i = 1; i <= 3 * n; i++) {
        sum += cnt[i] - 1;
        t++;
        if (sum < k) {
            sum = 0;
            t = 0;
        }
        ans = max(ans, t);
    }
    
    cout << ans << '\n';
}   
    
int32_t main ()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
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