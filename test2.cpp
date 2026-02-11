#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int N = 1 * 2 * 2 * 2 * 2;
    vector <int> v(N);
    for (int i = 0; i < N; i++) {
        v[i] = i;
    }
    // int ans = 1e11;
    do {
        int res = 0;
        for (int i = 1; i < N; i++) {
            res += (v[i] ^ v[i - 1]);
        }
        if (res == 36) {
            for (auto x : v) cout << x << ' ';
            cout << '\n';
            // break;
            // cout << "result: " << res << '\n';
            
        }
        // ans = min(ans, res);
    }while (next_permutation(v.begin(), v.end()));
    // cout << ans << '\n';
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

/*
  /\_/\
 (= ._.)
 / >  \>
*/