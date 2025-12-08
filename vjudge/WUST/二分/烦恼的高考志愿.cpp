#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 5;
int n, m;
int a[MAXN];
int b[MAXN];
int c[MAXN];

int cmp (int a1, int b1)
{
    return a1 < b1;
}

void solve ()
{
    cin >> m >> n;

    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    sort(a, a + m, cmp);

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(a, a + m, b[i]);

        if (it == a) {
            ans += abs(b[i] - *it);
        }else {
            ans += min(abs(b[i] - *it), abs(b[i] - *(it - 1)));
        }

    }

    cout << ans << endl;
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