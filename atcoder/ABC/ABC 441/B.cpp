#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int n, m; cin >> n >> m;
    string s1, s2; cin >> s1 >> s2;

    int q; cin >> q;

    while (q--) {
        string s; cin >> s;
        int N = s.size();
        bool founds1 = true;
        for (int i = 0; i < N; i++) {
            if (!count(s1.begin(), s1.end(), s[i])) {
                founds1 = false;
                break;
            }
        }
        bool founds2 = true;
        for (int i = 0; i < N; i++) {
            if (!count(s2.begin(), s2.end(), s[i])) {
                founds2 = false;
                break;
            }
        }
        if (founds1 && !founds2) {
            cout << "Takahashi" << '\n';
        }else if (!founds1 && founds2) {
            cout << "Aoki" << '\n';
        }else {
            cout << "Unknown" << '\n';
        }
    }   
}   

signed main ()
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