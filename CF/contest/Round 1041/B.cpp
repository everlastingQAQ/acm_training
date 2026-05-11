#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 100003;

void solve ()
{
    int n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    if (x == 1 || x == n) {
        cout << 1 << '\n';
        return;
    }
    s = ' ' + s;
    int l = x - 1;
    while (l >= 1 && s[l] == '.') {
        l--;
    }
    int r = x + 1;
    while (r <= n && s[r] == '.') {
        r++;
    }

    if (s[x - 1] == '#' || s[x + 1] == '#') {
        cout << min(x, n - x + 1) << '\n';
    }else {
        cout << max(min(x, n - r + 2), min(l + 1, n - x + 1)) << '\n';
    }
    
}   
    
int32_t main ()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int _ = 1;
    cin >> _;
    while (_--)     {
        solve();
    }
    return 0;
} 

/*
  /\_/\
 (= ._.)
 / >  \>
*/