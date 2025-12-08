#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 5;
const double eps = 1e-5;

int cmp (int a1, int b1)
{
    return a1 > b1;
}

void solve ()
{
    int n;
    cin >> n;

    int a[MAXN];
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    int mx = a[2];
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            mx = max(mx, a[i]);
            mx = max(mx, a[i - 1]);
            a[i] = mx;
        }
        if (i % 2 == 1) {
            //cout << mx << ' ' << a[i] << endl;
            if (a[i] < mx) {
                if (i + 1 <= n && a[i] > a[i + 1]) {
                    mx = max(mx, a[i]);
                    mx = max(mx, a[i + 1]);
                    if (a[i] > mx) {
                        ans += a[i] - mx + 1;
                    }
                }
            }else if (a[i] >= mx) {
                if (i != 1) {
                    ans += a[i] - mx + 1;
                    mx = max(a[i], mx);
                    a[i] = mx - 1;
                }
                //cout << ans << endl;
                if (i + 1 <= n && a[i] >= a[i + 1]) {
                    mx = max(mx, a[i]);
                    mx = max(mx, a[i + 1]);
                    //cout << mx << endl;
                    if (a[i] >= mx) {
                        ans += a[i] - mx + 1;
                    }
                }
            }
            //cout << ans << endl;
        }
    }

    cout << ans << endl;
}

int main ()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	int _ = 1;
	cin >> _;

    while (_--) {
        solve();
    }

    return 0;
}