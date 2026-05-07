#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	int n;
    cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    vector <int> pre(n + 1);
    int l = 1, r = 1;
    while (r <= n) {
        while (r <= n && v[l] == v[r]) {
            r++;
        }
        while (l < r) {
            pre[l] = r;
            l++;
        }
    }
    
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (r < pre[l]) {
            cout << -1 << ' ' << -1 << '\n';
            continue;
        }
        cout << l << ' ' << pre[l] << '\n';
    }
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