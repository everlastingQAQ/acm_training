#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    string s;
    cin >> s;
    if (s == "awdec") {
        cout << "Fantasy_Blue";
    }else if (s == "Fantasy_Blue") {
        cout << "awdec";
    }else {
        cout << "other";
    }
}   

int32_t main ()
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