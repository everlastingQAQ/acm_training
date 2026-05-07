#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <vector <int> > v(n + 1, vector <int> (n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v[i][j];
        }
    }

    map <int, int> mp;
    vector <int> cnt;
    for (int i = 1; i <= n; i++) {
        int c = 0;
        for (int j = n; j >= 1; j--) {
            if (v[i][j] == 1) {
                c++;
                continue;
            }else break;
        }
        cnt.push_back(c);
    }

    sort(cnt.begin(), cnt.end());
    int ans = 0;
    for (auto x : cnt) {
        if (x >= ans) {
            ans++;
        }else {
            continue;
        }
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