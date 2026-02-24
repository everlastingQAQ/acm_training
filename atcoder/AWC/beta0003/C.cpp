#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, k;
    cin >> n >> k;
    vector <array <i64, 2> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i][0] >> v[i][1];
    }
    ranges::sort(v | views::drop(1), [] (auto a, auto b) {
        return a[0] - a[1] > b[0] - b[1];
    });

    i64 ans = 0;
    for (int i = 1; i <= k; i++) {
        ans += v[i][1];
    }
    for (int i = k + 1; i <= n; i++) {
        ans += v[i][0];
    }

    cout << ans << '\n';
}   
    
int main ()
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