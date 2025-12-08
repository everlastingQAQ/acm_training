#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll r, x, d, n;
string s;

void solve ()
{
    cin >> r >> x >> d >> n >> s;
    ll ans = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '2' && r < x) {
            r -= d;
            ans++;
        }else if (s[i] == '1'){
            r -= d;
            ans++;
        }
        //cout << r << '\n';
    }

    cout << ans << '\n';
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