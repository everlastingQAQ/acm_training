#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	int n;
    i64 m;
    cin >> n >> m;
    vector <array <i64, 2> > v(n + 1);
    i64 r = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i][0] >> v[i][1];
        r = max(r, v[i][1]);
    }
    i64 l = 1;

    auto check = [&] (i64 md) -> bool {
        i64 sum = 0;
        for (int i = 1; i <= n; i++) {
            if (v[i][1] > md) {
                sum = 0;
            }else {
                sum += v[i][0];
            }
            if (sum >= m) return true;
        }
        return false;
    };

    while (l <= r) {
        i64 mid = l + (r - l) / 2;
        if (check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    cout << l << '\n';
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