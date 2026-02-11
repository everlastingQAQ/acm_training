#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> ind(n + 1, 0);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        ind[u]++;
        ind[v]++;
    }

    int ans = n;
    for (int i = 1; i <= n; i++) {
        if (ind[i] > 3) {
            ans = 0;
            break;
        }
        if (ind[i] == 3) {
            ans--;
        }
    }

    cout << ans << '\n';
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