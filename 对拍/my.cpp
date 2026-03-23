#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }  
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    int ans = 0;

    for (int i = n; i >= 1; i--) {
        if (a[i] == b[i]) {
            ans = max(ans, i);
        }
        if (i >= 2 && (a[i] == a[i - 1] || b[i] == b[i - 1])) {
            ans = max(ans, i - 1);
        }
        if (i >= 3 && (a[i] == a[i - 2] || b[i] == b[i - 2])) {
            ans = max(ans, i - 2);
        }
        if (i >= 3 && (a[i] == b[i - 2] || b[i] == a[i - 2])) {
            ans = max(ans, i - 2);
        }   
        if (i >= 4) {
            if (a[i] == b[i - 3] || b[i] == a[i - 3]) {
                ans = max(ans, i - 3);
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