#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    i64 k;
    cin >> n >> k;
    vector <i64> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    
    i64 ans = 0;
    int cur = 0;
    for (int i = 0; i <= 61; i++) {
        i64 cur = (1LL << i);
        for (int j = 1; j <= n; j++) {
            if (v[j] & cur) ans++;
            else if (k >= cur) {
                k -= cur;
                ans++;
            }
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