#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = ' ' + s;
    for (int i = 1; i <= n - k; i++) {
        if (s[i] == '1') {
            s[i] = '0';
            if (s[i + k] == '1') s[i + k] = '0';
            else s[i + k] = '1';
        }
    }
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}   
    
int32_t main ()
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