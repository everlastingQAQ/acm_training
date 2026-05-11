#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, k;
    cin >> n >> k;
    vector <array <int, 2> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i][0];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i][1];
        if (v[i][0] > v[i][1]) {
            swap(v[i][0], v[i][1]);
        }
        ans += v[i][1] - v[i][0];
    }

    ranges::sort(v | views::drop(1));

    int mn = 1e11;
    for (int i = 2; i <= n; i++) {
        mn = min(mn, max(0LL, 2 * (v[i][0] - v[i - 1][1])));
    }

    ans += mn;

    cout << ans << '\n';
}   
    
int32_t main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
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