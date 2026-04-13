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
const ll inf = LLONG_MAX;

ll n;

void solve ()
{
    cin >> n;
    if (n <= 26) {
        char c = 'a';
        for (int i = 0; i < n; i++) {
            cout << c;
            c++;
        }
    }else {
        char c = 'a';
        if (n & 1) {
            for (int i = 0; i < 25; i++) {
                cout << c;
                c++;
            }
            for (int i = 0; i < n - 25; i++) {
                cout << 'a';
            }
        }else {
            for (int i = 0; i < 26; i++) {
                cout << c;
                c++;
            }
            for (int i = 0; i < n - 26; i++) {
                cout << 'a';
            }
        }
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