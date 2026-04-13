#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int a, b, s;
    cin >> a >> b >> s;
    string aa, bb, ss;
    cin >> aa >> bb >> ss;
    for (int i = 0; i <= ss.size() - a; i++) { 
        string t = ss.substr(i, a);
        if (t == aa) {
            ss.replace(ss.begin() + i, ss.begin() + i + a, bb);
            i += b - 1;
        }
    } 
    cout << ss << '\n';
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}