#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

string n;
ll k;

void solve ()
{
    cin >> n >> k;

    vector <char> stk;

    for (int i = 0; i < n.size(); i++) {
        if (stk.empty()) {
            stk.emplace_back(n[i]);
            continue;
        }
        while (!stk.empty() && stk.back() > n[i] && k > 0) {
            stk.pop_back();
            k--;
        }
        stk.emplace_back(n[i]);
    }

    while (k > 0 && !stk.empty()) {
        stk.pop_back();
        k--;
    }

    for (auto x : stk) {
        cout << x;
    }
    cout << '\n';
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