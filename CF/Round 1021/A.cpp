#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;

void solve ()
{   
    string s; cin >> s;
    vector <int> v(10, 0);
    for (int i = 0; i < 10; i++) {
        v[s[i] - '0']++;
    }
    vector <int> ans(10);
    for (int i = 0; i < 10; i++) {
        ll t = 9 - i;
        while (v[t] == 0) {
            t++;
        }
        ans[i] = t;
        v[t]--;
    }

    for (auto x : ans) {
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