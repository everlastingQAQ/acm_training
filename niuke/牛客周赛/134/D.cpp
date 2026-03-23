#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <i64> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    int l = 1, r = 1;
    deque <int> dq;
    int ans = 0;
    while (r <= n) {
        while (r <= n && v[r] - v[l] <= 1) {
            dq.push_back(v[r]);
            r++;
        }
        int t = r - l + 1;
        ans += t * (t - 1) / 2;
        r++;
        l = r;
    }

    cout << ans << '\n';
}   
    
int main ()
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