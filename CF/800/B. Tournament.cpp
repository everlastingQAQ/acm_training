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
    int n, j, k;
    cin >> n >> j >> k;

    memset(a, 0, sizeof(a));

    int maxium = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxium = max(maxium, a[i]);
    }

    if (k > 1) {
        cout << "YES" << endl;
        return;
    }

    if (a[j] == maxium) {
        cout << "YES" << endl;
    }else {
        cout << "NO" << endl;
    }
    
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