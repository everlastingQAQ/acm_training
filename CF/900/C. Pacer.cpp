#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 5;
int a[MAXN];
int b[MAXN];

void solve ()
{
    int n, m;
    cin >> n >> m;
    memset(a, 0, sizeof(a));

    int ans = 0;
    a[0] = 0;
    b[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        if (abs(a[i] - a[i - 1]) % 2 == abs(b[i] - b[i - 1]) % 2) {
            ans += a[i] - a[i - 1];
        }else {
            ans += a[i] - a[i - 1] - 1;
        }
    }

    ans += m - a[n];

    cout << ans << endl;

    return;
}

int main ()
{
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int _ = 1;
	cin >> _;

    while (_--) {
        solve();
    }

    return 0;
}