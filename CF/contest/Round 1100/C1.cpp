#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    vector <int> pos;
    int idx = n;
    while (idx >= 1 && v[idx] <= 0) {
        idx--;
    }
    if (idx >= 1) pos.push_back(idx);
    for (int i = idx - 1; i >= 1; i--) {
        if ((v[i] > 0 && v[i + 1] <= 0) || v[i] <= 0 && v[i + 1] > 0) {
            pos.push_back(i);
        }
    }
    cout << pos.size() << '\n';
    for (auto x : pos) {
        cout << x << " \n"[x == pos.back()];
    }
}

int32_t main ()
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