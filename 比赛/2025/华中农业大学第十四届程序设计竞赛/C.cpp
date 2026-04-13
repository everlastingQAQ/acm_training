#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 1e9 + 7;

string s;
ll n;

void solve ()
{
    cin >> n >> s;
    bool found = false;
    for (char c : s) {
        if (c == 'e') {
            found = true;
        }
        if (found) {
            if (c == 'z') {
                cout << "easy" << '\n';
                return;
            }
        }
    }
    cout << "hard" << '\n';
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