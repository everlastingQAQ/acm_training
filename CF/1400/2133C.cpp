#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <vector <int> > v(n + 1);
    int mx = -1;
    int s = -1;
    for (int i = 1; i <= n; i++) {
        int t;
        cout << '?' << ' ' << i << ' ' << n << ' ';
        for (int j = 1; j <= n; j++) {
            cout << j << ' ';
        }
        cout << endl;
        cin >> t;
        if (t > mx) {
            s = i;
            mx = t;
        }
        v[t].push_back(i);
    }

    vector <int> ans;
    ans.push_back(s);
    int pre = s;

    for (int i = mx - 1; i >= 1; i--) {
        for (auto u : v[i]) {
            int t;
            cout << '?' << ' ' << pre << ' ' << 2 << ' ' << pre << ' ' << u << endl;
            cin >> t;
            if (t == 2) {
                pre = u;
                ans.push_back(u);
                break;
            }
        }
    }

    cout << '!' << ' ' << mx << ' ';
    for (auto x : ans) {
        cout << x << ' ';
    }
    cout << endl;
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 