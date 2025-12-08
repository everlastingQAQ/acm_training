#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 4e6 + 10;
int a[MAXN];

void solve ()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int mx = a[1] - 1;

    bool found = false;
    int sum = 0, l = 1, r = 1;
    for (int i = 1, j = 1; j <= n; j++) {
        sum += a[j];

        while (sum > m) {
            sum -= a[i];
            i++;
        }

        if (sum > mx && sum <= m) {
            mx = max(mx, sum);
            l = i;
            r = j;
            found = true;
        }

    }

    cout << l << ' ' << r << ' ' << mx << endl; 
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