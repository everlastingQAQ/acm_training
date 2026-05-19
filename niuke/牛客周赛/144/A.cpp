#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    int cnt[5] = {};
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        cnt[c - 'A']++;
    }
    for (int i = 1; i < 4; i++) {
        if (cnt[i] != cnt[0]) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int32_t main()
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