#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int p = n / 2;
    char c = s[p];
    int l = p;
    while (l >= 0 && s[l] == c) {
        l--;
    }
    int r = p;
    while (r < n && s[r] == c) {
        r++;
    }
    cout << r - l - 1 << '\n';
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