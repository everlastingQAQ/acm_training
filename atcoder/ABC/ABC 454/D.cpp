#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    string s, t;
    cin >> s >> t;
    auto cal = [&] (string &s) -> string {
        string a;
        for (auto c : s) {
            a.push_back(c);
            while (a.size() >= 4 && a.substr(a.size() - 4, 4) == "(xx)") {
                a.erase(a.size() - 4, 4);
                a = a + "xx";
            }
        }
        return a;
    };
    cout << (cal(s) == cal(t) ? "Yes\n" : "No\n");
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