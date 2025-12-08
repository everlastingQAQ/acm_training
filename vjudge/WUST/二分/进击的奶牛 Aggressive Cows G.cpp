#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 1;
int a[MAXN];
int n, m;

bool cmp (int a1, int b1)
{
    return a1 < b1;
}

bool check (int x)
{
    int cnt = 1;
    int nw = 0;

    for (int i = 1; i < n; i++) {
        if (a[i] - a[nw] >= x) {
            cnt++;
            nw = i;
        }
    }

    return cnt >= m;
}

void solve ()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n, cmp);
    int l = 0, r = a[n - 1] - a[0];

    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (check(mid)) {
            l = mid;
        }else {
            r = mid - 1;
        }
    }

    cout << l << endl;
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