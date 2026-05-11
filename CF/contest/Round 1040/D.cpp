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
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int cnt1 = 0;
        for (int j = i - 1; j >= 1; j--) {
            if (v[j] > v[i]) cnt1++;
        }
        int cnt2 = 0;
        for (int j = i + 1; j <= n; j++) {
            if (v[j] > v[i]) cnt2++;
        }
        ans += min(cnt1, cnt2);
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