#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<ll> a(q);
    for (int i = 0; i < q; i++) cin >> a[i];

    ll A = count(s.begin(), s.end(), 'A');
    ll B = count(s.begin(), s.end(), 'B');

    for (int i = 0; i < q; i++) {
        if (B == 0) {
            cout << a[i] << "\n";
        } else {
            ll ans = 0;
            while (a[i]) {
                for (char j : s) {
                    if (a[i] == 0) break;
                    ans++;
                    if (j == 'A') a[i] -= 1;
                    else a[i] /= 2;
                }
            }
            cout << ans << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
