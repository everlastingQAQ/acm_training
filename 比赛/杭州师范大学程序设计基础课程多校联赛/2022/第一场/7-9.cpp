#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 5;
const double eps = 1e-5;

void solve ()
{
    int n, k;
    cin >> n >> k;

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ((i + j) % k == 0) {
                for (int l = 1; l <= n; l++) {
                    if ((i + l) % k == 0 && (j + l) % k == 0) {
                        cnt++;
                    }
                }
            }
        }
    }

    cout << cnt;
}

int main ()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	int _ = 1;
	//cin >> _;

    while (_--) {
        solve();
    }

    return 0;
}