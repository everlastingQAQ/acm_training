#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 1e6 + 5;
const double eps = 1e-5;
const ll mod = 998244353;
string s1, s2;
ll n;

void solve ()
{
    cin >> n >> s1 >> s2;
    ll a[27];
    memset(a, 0, sizeof(a));

    for (char x : s1) {
        a[x - 'a']++;
    }

    for (char x : s2) {
        a[x - 'a']--;
    }

    for (int i = 1; i <= 26; i++) {
        if (a[i] != 0) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;

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