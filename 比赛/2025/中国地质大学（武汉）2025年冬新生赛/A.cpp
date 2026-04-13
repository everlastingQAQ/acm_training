#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

string s1, s2;

void solve ()
{
    cin >> s1 >> s2;
    ll t = (s1[s1.size() - 1] - '0' + s2[s2.size() - 1] - '0') % 10;
    cout << t << '\n';
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