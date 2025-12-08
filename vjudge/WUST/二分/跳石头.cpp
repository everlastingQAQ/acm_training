#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 5e4 + 5;
int l, n, m;
int a[MAXN];

int cmp (int a1, int b1)
{
    return a1 < b1;
}

bool check (int x)
{
    int cnt = 0;
    bool legal = true;

    for (int i = 0, j = 1; j <= n + 1; j++) {
        if (a[j] - a[i] < x) {
            cnt++;
            if (cnt > m) {
                legal = false;
                break;
            }
        }else {
            i = j;
        }   
    }

    return legal;
}

void solve ()
{
    cin >> l >> n >> m;
    a[0] = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    a[n + 1] = l;

    int r = a[n + 1], lf = a[0];

    int ans = 0;

    while (lf <= r) {
        int mid = lf + (r - lf) / 2;
        if (check(mid)) {
            lf = mid + 1;
            ans = mid;
        }else {
            r = mid - 1;
        }
    }

    cout << ans << endl;

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