#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    string s;
    cin >> s;
    int cn = 0;
    string ss;
    for (auto c : s) {
        if (c != '4') ss.push_back(c);
        else cn++;
    }
    s = ss;
    bool ok = false;
    int cc = 0;
    int cnt = 0;
    int ccc = 0;
    for (auto c : s) {
        if (c == '1' || c == '3') {
            cc++;
            ok = true;
        }
        if (c == '2') {
            cnt += cc;
            cc = 0;
            if (ok) ccc++;
        } 
    }
    cout << cn + min(cnt, ccc) << '\n';
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