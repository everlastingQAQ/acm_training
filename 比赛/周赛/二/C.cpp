#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 998244353;
    
ll n, q;
string a, b;

void solve ()
{   
    cin >> n >> q >> a >> b;
    a = " " + a; b = " " + b;
    vector <vector <ll> > v(n + 1, vector <ll> (26, 0));
    vector <vector <ll> > s(n + 1, vector <ll> (26, 0));
    for (int i = 1; i <= n; i++) {
        v[i][a[i] - 'a']++;
        for (int j = 0; j < 26; j++) {
            v[i][j] += v[i - 1][j];
        }
    }
     
    for (int i = 1; i <= n; i++) {
        s[i][b[i] - 'a']++;
        for (int j = 0; j < 26; j++) {
            s[i][j] += s[i - 1][j];
        }
    }

    while (q--) {
        ll l, r;
        cin >> l >> r;
        vector <ll> c(26);
        for (int i = 0; i < 26; i++) {
            if (l == 1) c[i] = v[r][i] - 0;
            else c[i] = v[r][i] - v[l - 1][i];
        }
        // cout << '\n';
        vector <ll> d(26);
        for (int i = 0; i < 26; i++) {
            if (l == 1) d[i] = s[r][i] - 0;
            else d[i] = s[r][i] - s[l - 1][i];
            // cout << s[r][i] << ' ';
        }
        // cout << '\n';

        ll ans = 0;
        for (int i = 0; i < 26; i++) {
            if (c[i] > d[i]) {
                ans += c[i] - d[i];
            }
        }
        cout << ans << '\n';
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