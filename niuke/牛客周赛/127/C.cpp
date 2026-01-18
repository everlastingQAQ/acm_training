#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    string s; cin >> s; 
    int n = s.size();
    vector <int> v(n + 1);
    for (int i = 0; i < n; i++) {
        v[i + 1] = s[i] - '0';
    }

    int idx = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i] >= 5) {
            idx = i;
            break;
        }
    }

    if (idx == 0 && v[n] < 5) {
        v[n] = 0;
        for (int i = 1; i <= n; i++) {
            cout << v[i];
        }
        cout << '\n';
        return;
    }

    for (int i = idx; i <= n; i++) {
        v[i] = 0;
    }

    v[idx - 1]++;
    for (int i = idx - 1; i >= 1; i--) {
        if (v[i] == 10) {
            v[i] = 0;
            v[i - 1]++;
        }
    }

    if (v[0] == 1) {
        cout << v[0];
    }

    for (int i = 1; i <= n; i++) {
        cout << v[i];
    }

    cout << '\n';
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