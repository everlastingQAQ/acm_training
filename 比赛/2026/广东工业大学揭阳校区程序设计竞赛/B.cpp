#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int p[13] = {0, 0, 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1};

void solve ()
{
    int n;
    cin >> n;
    if (n > 12 || n == 1) {
    	cout << 0 << '\n';
    	return;
    }
    int t1 = 0;
    for (int i = 2; i < n; i++) {
    	t1 += p[i];
    }
    int t2 = p[n];
    int ans = t1 * 30 + t2 * 15;
    ans /= 36;
    cout << ans << '\n';
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 