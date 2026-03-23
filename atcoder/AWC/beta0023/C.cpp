#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <i64> v(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        pre[i] = pre[i - 1] + v[i];
    }

    for (int i = 1; i <= m; i++) {
        i64 s, l, r;
        cin >> s >> l >> r;
        cout << s + pre[r] - pre[l - 1] << '\n';
    }
}   
    
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 