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

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char a = v[i][j];

            if (j < m) {
                char b = v[i][j + 1];
                if (i < n) {
                    char c = v[i + 1][j + 1];
                    if (a != b && a != c && b != c) {
                        ans++;
                    }
                }
                if (i > 1) {
                    char c = v[i - 1][j + 1];
                    if (a != b && a != c && b != c) {
                        ans++;
                    }
                }
            }

            if (j > 1) {
                char b = v[i][j - 1];
                if (i < n) {
                    char c = v[i + 1][j - 1];
                    if (a != b && a != c && b != c) {
                        ans++;
                    }
                }
                if (i > 1) {
                    char c = v[i - 1][j - 1];
                    if (a != b && a != c && b != c) {
                        ans++;
                    }
                }
            }
            if (i < n) {
                char b = v[i + 1][j];
                if (j < m) {
                    char c = v[i + 1][j + 1];
                    if (a != b && a != c && b != c) {
                        ans++;
                    }
                }
                if (j > 1) {
                    char c = v[i + 1][j - 1];
                    if (a != b && a != c && b != c) {
                        ans++;
                    }
                }
            }
            if (i > 1) {
                char b = v[i - 1][j];
                if (j < m) {
                    char c = v[i - 1][j + 1];
                    if (a != b && a != c && b != c) {
                        ans++;
                    }
                }
                if (j > 1) {
                    char c = v[i - 1][j - 1];
                    if (a != b && a != c && b != c) {
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans / 2 << '\n';
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