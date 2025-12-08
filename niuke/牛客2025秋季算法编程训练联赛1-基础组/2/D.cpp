#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 500 + 1;

bool judge (int a, int b, int c, int d, int e, int f)
{
    ll dx = (a - b) * (a - b);
    ll dxx = (a - c) * (a - c);
    ll dxxx = (b - c) * (b - c);

    ll dy = (d - e) * (d - e);
    ll dyy = (d - f) * (d - f);
    ll dyyy = (e - f) * (e - f);

    ll d1 = dx + dy;
    ll d2 = dxx + dyy;
    ll d3 = dxxx + dyyy;

    if (d1 > d2 + d3 || d2 > d1 + d3 || d3 > d1 + d2) {
        return true;
    }else {
        return false;
    }

}

void solve ()
{
    int n;
    cin >> n;

    int a[MAXN][2];

    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
    }

    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int l = j + 1; l < n; l++) {
                if ((a[l][0] - a[i][0]) * (a[l][1] - a[j][1]) == (a[l][1] - a[i][1]) * (a[l][0] - a[j][0])) {
                    continue;
                }
                if (judge(a[i][0], a[j][0], a[l][0], a[i][1], a[j][1], a[l][1])) {
                    cnt++;
                }
            }
        }
    }

    cout << cnt;
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