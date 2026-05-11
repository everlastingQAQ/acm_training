#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    vector <int> v(n + 1);
    vector <int> a;
    
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        v[i] = s[i] - '0';
        sum += v[i];
        if (i == 1) {
            a.push_back(max(0, v[i] - 1));
        }else {
            a.push_back(v[i]);
        }
    }

    if (sum <= 9) {
        cout << 0 << '\n';
        return;
    }

    ranges::sort(a, greater<>());
    int ans = 0;

    for (int i = 0; i < n; i++) {
        sum -= a[i];
        ans++;
        if (sum <= 9) {
            cout << ans << '\n';
            return;
        }
    }

}   
    
int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 