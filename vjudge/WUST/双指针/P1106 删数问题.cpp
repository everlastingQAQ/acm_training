#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
string s;
ll k;

void solve ()
{
    cin >> s >> k;

    vector <char> stk;

    for (int i = 0; i < s.size(); i++) {
        if (stk.empty()) {
            stk.emplace_back(s[i]);
            continue;
        }
        while (stk.back() > s[i] && k > 0 && !stk.empty()) {
            stk.pop_back();
            k--;
        }
        stk.emplace_back(s[i]);
    }

    while (k > 0 && !stk.empty()) {
        stk.pop_back();
        k--;
    }

    bool found = true;

    for (auto x : stk) {
        if (x == '0' && found) {
            continue;
        }
        found = false;
        cout << x;
    }
    
    if (found) {
        cout << 0;
    }else {
        return;
    }

}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}