#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, dist;
    cin >> n >> dist;
    vector <i64> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    sort(v.begin() + 1, v.end());

    int cnt = 0;
    i64 cur = v[1];
    for (int i = 2; i < n; i++) {
        if (v[i + 1] <= cur + dist) {
            cnt++;
            continue;
        }   
        cur = v[i];
    }

    cout << cnt << '\n';
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