#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 5;
const double eps = 1e-5;
ll a[MAXN];
int n, m;

int cmp (int a1, int b1)
{
    return a1 > b1;
}

void solve ()
{
    cin >> n >> m;

    memset(a, 0, sizeof(a));

    int pos = 0;
    int neg = 0;
    int cnt_0 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > 0) {
            pos++;
        }else if (a[i] < 0) {
            neg++;
        }else if (a[i] == 0) {
            cnt_0++;
        }
    }

    if (pos < m && pos + neg - 1 < m || pos > m && cnt_0 == 0 && neg == 0) {
        cout << -1 << endl;
    }else {
        cout << abs(m - pos) << endl;
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