#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (i < k) s[i] = toupper(s[i]);
        else s[i] = tolower(s[i]);
    }
    cout << s;
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}