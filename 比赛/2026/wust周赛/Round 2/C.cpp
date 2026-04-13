#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

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

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (v[i][j] >= '1' && v[i][j] <= '9') {
                int t = v[i][j] - '0';
                for (int k = 1; k <= n; k++) {
                    for (int l = 1; l <= m; l++) {
                        if (v[k][l] >= '1' && v[k][l] <= '9') continue;
                        if (abs(k - i) + abs(l - j) <= t) {
                            v[k][l] = '.';
                        }
                    }
                }
                v[i][j] = '.';
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << v[i][j];
        }
        cout << '\n';
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
