#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int l = 0;
    while (l < n && s[l] != 'p') {
        l++;
    }
    int r = n - 1;
    while (r >= 0 && s[r] != 's') {
        r--;
    }
    
    if (l == n || r == 0 || l == n - 1 || r == -1) {
        cout << "YES\n";
    }else {
        cout << "NO\n";
    }
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