#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n = 11, m;
    cin >> m;
    vector <int> v(n + 1), a(n + 1);
    for (int i = 1; i < n; i++) {
        cin >> v[i];
    }
    a = {0, 1, 5, 10, 20, 50, 100, 200, 500, 1000, 2000};

    auto dfs = [&] (auto self, int t, int pos, int cur) -> void {
        
    };
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