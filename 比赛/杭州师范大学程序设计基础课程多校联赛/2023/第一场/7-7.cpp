#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 10000 + 5;

bool cmp (int a1, int b1)
{
    return a1 < b1;
}

void solve ()
{
    int n, m;
    cin >> n >> m;

    int a[MAXN];
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    sort(a, a + m, cmp);

    int sum = 20;

    if (n - m >= 2) {
        cout << sum;
    }else {
        sum += a[2 - (n - m) - 1];
        cout << sum;
    }
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