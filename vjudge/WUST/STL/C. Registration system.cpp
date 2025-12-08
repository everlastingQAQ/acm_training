#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n;

void solve ()
{
    cin >> n;
    map <string, ll> mp;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (mp.find(s) == mp.end()) {
            mp[s] = 0;
            cout << "OK" << '\n';
        }else {
            mp[s]++;
            cout << s << mp[s] << '\n';
        }
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