#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	int n;
    cin >> n;
    vector <int> v(n + 1);
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        a[v[i]]++;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) cnt++;
    }
    int ans = (cnt - cnt / 2) * 2;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) continue;
        if (a[i] != 0) sum++;
    }
    ans += sum;
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