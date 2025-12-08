#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6;
int a[MAXN];

void solve ()
{
    int n;
    cin >> n;

    memset(a, 0, sizeof(a));

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 0, r = 0, cnt = 0;

    while (l < n) {
        if (a[l] == l) {
            l++;
        }else {
            int mx = a[l];
            r = l + 1;
            mx = max(mx, a[r]);
            while (mx > r) {
                r++;
                mx = max(mx, a[r]);
            }
            cnt += r - l + 1;
            l = r + 1;
        }
    }

    cout << cnt << endl;
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