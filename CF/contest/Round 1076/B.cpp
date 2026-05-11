#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n; cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    int pos1 = 0;
    int t = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i] != n - i + 1) {
            pos1 = i;
            t = n - i + 1;
            break;
        }
    }

    if (pos1 == 0) {
        for (int i = 1; i <= n; i++) {
            cout << v[i] << " \n"[i == n];
        }
        return;
    }

    int pos2 = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i] == t) {
            pos2 = i;
            break;
        }
    }
    if (pos1 > pos2) swap(pos1, pos2);
    // cout << pos1 << ' ' << pos2 << '\n';

    reverse(v.begin() + pos1, v.begin() + pos2 + 1);

    for (int i = 1; i <= n; i++) {
        cout << v[i] << " \n"[i == n];
    }
}   
    
signed main ()
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