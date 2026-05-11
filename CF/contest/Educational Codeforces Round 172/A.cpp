#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	int n, k;
    cin >> n >> k;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    sort(v.begin() + 1, v.end(), greater<>());
    int sum = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (sum + v[i] <= k) {
            sum += v[i];
        }else if (sum + v[i] > k) {
            ans = k - sum;
            break;
        }
        if (i == n) {
            ans = k - sum;
        }
    }
    cout << ans << '\n';
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}