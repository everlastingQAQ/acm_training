#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    int c0 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (v[i] == 0) c0++;
    }
    if (c0 == 0) {
        cout << n << '\n';
        return;
    }
    int pos = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i] == 0) {
            pos = i;
            break;
        }
    }
    
    vector <int> b;
    b.push_back(0);
    for (int i = 1; i <= n; i++) {
        if (v[i] == 0 && i != pos) continue;
        b.push_back(v[i]);
    }
    int m = b.size();

    int mex = 0;
    map <int, int> mp;
    vector <int> a(m);
    for (int i = m - 1; i >= 1; i--) {
        mp[b[i]] = true;
        while (mp[mex]) {
            mex++;
        }
        a[i] = mex;
    }

    vector <int> mn(m);
    mn[1] = b[1];
    for (int i = 2; i < m; i++) {
        mn[i] = min(mn[i - 1], b[i]);
    }
    for (int i = m - 2; i >= 1; i--) {
        if (a[i + 1] > mn[i]) {
            cout << n - c0 << '\n';
            return;
        }
    }
    cout << n - c0 + 1 << '\n';
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