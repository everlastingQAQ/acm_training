#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <vector <char> > v(n + 1, vector <char> (m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }
    int cnt1 = 0;
    for (int i = 1; i <= n; i++) {
        int t1 = 0;
        for (int j = 1; j <= m; j++) {
            t1 ^= (v[i][j] - '0');
        }
        if (t1 == 1) cnt1++;
    }
    int cnt2 = 0;
    for (int j = 1; j <= m; j++) {
        int t2 = 0;
        for (int i = 1; i <= n; i++) {
            t2 ^= (v[i][j] - '0');
        }
        if (t2 == 1) cnt2++;
    }
    cout << max(cnt1, cnt2) << '\n';
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