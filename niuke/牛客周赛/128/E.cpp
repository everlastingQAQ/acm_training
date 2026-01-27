#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    string s; cin >> s;
    int n = s.size();
    s = ' ' + s;
    vector <int> v(n + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') v[i] = 1, cnt++;
        else if (s[i] == '2') v[i] = 2;
        else if (s[i] == '0') v[i] = 0;
    }

    int l = 1, r = n;

    if (cnt & 1) {
        while (l <= n && v[l] != 1) l++;
        l++;
    }

    while (l <= r) {
        while (l <= r && v[l] != 1) {
            l++;
        }
        while (r >= l && v[r] != 1) {
            r--;
        }
        if (l == r) break;
        if (v[l] == 1 && v[r] == 1) v[l] = -1, v[r] = 2;
        // cout << l << ' ' << r << '\n';
        l++, r--;
    }

    for (int i = 1; i <= n; i++) {
        if (v[i] == -1) continue;
        cout << v[i];
    }
}   
    
signed main ()
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