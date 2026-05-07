#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n = 20;
    vector <vector <int> > v(n + 1, vector <int> (n + 1));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            v[i][j] = (i ^ j) * (i | j) * (i & j);
            // cout << i << ' ' << j << ' ' << x << '\n';
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%3d ", v[i][j]);

            // if(v[i][j] == 0)
            // {
            //     cout << i << " " << j << endl;
            // }
        }
        cout << '\n';
    }
}

int main ()
{
    // ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}