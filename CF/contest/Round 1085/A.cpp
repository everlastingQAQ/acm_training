#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    string s;
    cin >> n >> s;
    int c1 = 0, c0 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') c1++;
        else c0++;
    }
    int a1 = c1;
    int a2 = c1;

    for (int i = 1; i < n; i++) {
        if (s[i] == '0' && s[i - 1] == '1' && s[i + 1] == '1') {
            a2++;
            a1++;
            s[i] = '1';
        }
    }

    int l = 0, r = 0;
    while (r < n) {
        while (r < n && s[r] == '1') {
            r++;
        }
        if (r - l + 1 - 1 >= 3) {
            a1 -= (r - l + 1 - 1 - 1) / 2;
        }
        r++;
        l = r;
    }

    cout << a1 << ' ' << a2 << '\n';
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