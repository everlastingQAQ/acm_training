#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

string s;

void solve ()
{
    cin >> s;
    ll n = s.size();
    vector <char> ans;
    
    for (int i = 0; i < n; i++) {
        if (i == (n - 1) / 2) {
            continue;
        }else {
            ans.emplace_back(s[i]);
        }
    }

    for (auto x : ans) {
        cout << x;
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