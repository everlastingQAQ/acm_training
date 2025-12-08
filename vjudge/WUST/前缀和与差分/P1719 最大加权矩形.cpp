#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 120 + 2;

void solve ()
{
    int n;
    cin >> n;

    int a[MAXN][MAXN];
    int sum[MAXN][MAXN];
    memset(a, 0, sizeof(a));
    memset(sum, 0, sizeof(sum));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            sum[i][j] += a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }

    int mx = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                for (int l = 1; l <= n; l++) {
                    if (k < i || l < j) continue;
                    mx = max(mx, sum[k][l] - sum[k][j - 1] - sum[i - 1][l] + sum[i - 1][j - 1]);
                }
            }
        }
    }

    cout << mx << endl;
    
}

int main ()
{
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int _ = 1;
	//cin >> _;

    while (_--) {
        solve();
    }

    return 0;
}