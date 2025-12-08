#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e4 + 5;
const double eps = 1e-5;
int a[MAXN];
int n, k;

int cmp (int a1, int b1)
{
    return a1 > b1;
}

void solve ()
{
    cin >> n >> k;

    memset(a, 0, sizeof(a));

    int cnt_0 = 0;
    int cnt_1 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) {
            cnt_0++;
        }else if (a[i] == 1) {
            cnt_1++;
        }
    }

    if (cnt_0 >= k || cnt_1 > k / 2) {
        cout << 0 << endl;
        return;
    }else {
        cout << 1 << endl;
        return;
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