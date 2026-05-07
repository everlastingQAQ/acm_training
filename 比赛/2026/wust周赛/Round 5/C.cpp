#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, k;
    cin >> n >> k;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    int l = 1, r = 1;
    map <int, int> mp;
    int cnt = 0;
    while (r <= k) {
        if (!mp[v[r]]) {
            cnt++;
        }  
        mp[v[r]]++;
        r++;
    }
    int ans = 0;
    while (r <= n + 1) {
        if (cnt == k) {
            ans++;
        }
        if (r == n + 1) break;
        mp[v[l]]--;
        if (mp[v[l]] == 0) {
            cnt--;
        }
        if (mp[v[r]] == 0) {
            cnt++;
        }
        mp[v[r]]++;
        l++;
        r++;
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