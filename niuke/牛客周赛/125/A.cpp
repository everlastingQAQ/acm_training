#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<string, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 998244353;

void solve ()
{
    string s; cin >> s;
    bool foundA = false;
    bool foundB = false;
    bool foundD = false;
    for (char c : s) {
        if (c == 'A') {
            foundA = true;
        }else if (c == 'B') {
            foundB = true;
        }else if (c == 'D') {
            foundD = true;
        }else {
            cout << 0;
            return;
        }
    }
    if (foundA + foundB + foundD == 0) {
        cout << 0;
    }else if (foundA + foundB + foundD != 3) {
        cout << 2;
    }else {
        cout << 4;
    }
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