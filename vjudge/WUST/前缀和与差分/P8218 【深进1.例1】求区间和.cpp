#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 2;

bool cmp (int a1, int b1)
{
    return a1 < b1;
}

void solve ()
{
    int n;
    cin >> n;
    int a[MAXN];
    int sum[MAXN];
    sum[0] = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = a[i] + sum[i - 1];
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << endl;
    }

    return;

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