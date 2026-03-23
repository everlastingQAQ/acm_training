#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    i64 ans = 0;
    vector <i64> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    
    for (int i = 1; i <= n; i++) {
        i64 cur = 0;
        int l = i, r = i + 1;
        while (l > 1 && v[l - 1] + cur < v[i]) {
            l--;
            cur += v[l];
        }
        while (l <= i) {
            while (r <= n && cur + v[r] < v[i]) {
                cur += v[r];
                r++;
            }
            ans += r - i;
            cur -= v[l];
            l++;
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