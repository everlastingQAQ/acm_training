#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 5;
const double eps = 1e-5;
int n, k;
int a[MAXN];

bool check (int x)
{
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        ans += a[i] / x;
    }

    return ans >= k;
}

int cmp (int a1, int b1)
{
    return a1 < b1;
}

void solve ()
{
    cin >> n >> k;

    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(a[i], mx);
    }

    int r = mx, l = 0;

    while (l + 1 < r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            l = mid;
        }else {
            r = mid;
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