#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <map <int, int> > mp(n + 1);
    vector <vector <int> > v(n + 1, vector <int> (n + 1));
    for (int i = 1; i <= n; i++) {
        map <int, int> mp1;
        for (int j = 1; j <= n; j++) {
            int t = 0;
            while (mp1[t] || mp[j][t]) {
                t++;
            }
            mp[j][t] = true;
            mp1[t] = true;
            v[i][j] = t;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << v[i][j] << " \n"[j == n];
        }
    }
} 

int main ()
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