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

void input (int a[MAXN])
{
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n, cmp);
}

void solve ()
{
    cin >> n;

    input(a);
    input(b);
    input(c);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto ita = lower_bound(a, a + n, b[i]);
        if (ita == a) continue;
        auto itc = upper_bound(c, c + n, b[i]);
        if (itc == c + n) continue;
        ans += (ita - a) * (n - (itc - c));
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