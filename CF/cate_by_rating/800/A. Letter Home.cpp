#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 5;
int a[MAXN];

int cmp (int a1, int b1)
{
    return a1 > b1;
}

void solve ()
{
    int n, s;
    cin >> n >> s;

    memset(a, 0, sizeof(a));

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (s >= a[n - 1]) {
        cout << s - a[0] << endl;
    }else if (s < a[n - 1] && s >= a[0]) {
        int p = a[n - 1] - s;
        int q = s - a[0];
        int maxium = max(p, q);
        int minium = min(p, q);
        cout << minium * 2 + maxium << endl;
    }else if (s < a[0]) {
        cout << a[n - 1] - s << endl;
    }
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