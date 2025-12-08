#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 10;
int a[MAXN];

int cmp (int a1, int b1) {
    return a1 < b1;
}

void solve ()
{
    ll n, c;
    cin >> n >> c;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n, cmp);

    ll cnt = 0;
    for (int i = 0, j = 0; i < n; i++) {
        while (j < n && a[j] - a[i] < c) {
            j++;
        }
        if (j < n && a[j] - a[i] == c) {
            int p = j + 1;
            int count = 1;
            int q = a[i];
            while (p < n && a[p] == a[j]) {
                p++;
                count++;
            }
            j = p;
            cnt += count;
            while (i < n && a[i + 1] == q) {
                cnt += count;
                i++;
            }
        }
    }

    cout << cnt << endl;
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