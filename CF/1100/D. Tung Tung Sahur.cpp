#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 1e6 + 5;
const double eps = 1e-5;
const ll mod = 998244353;
string s1, s2;//错误代码

void solve ()
{
    cin >> s1 >> s2;

    if (s1 == s2) {
        cout << "YES" << endl;
        return;
    }
    
    ll l = 0, r = 0;

    while (l < s1.size()) {
        char t = s1[l];
        ll cnt1 = 0;
        while (r < s2.size() && s2[r] == t && cnt1 < 2) {
            cnt1++;
            r++;
        }
        if (cnt1 == 0) {
            cout << "NO" << endl;
            return;
        }
        l++;
    }

    if (r != s2.size()) {
        cout << "NO" << endl;
    }else {
        cout << "YES" << endl;
    }

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