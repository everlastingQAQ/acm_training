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
    
ll n;
string s;

void solve ()
{
    cin >> n >> s;
    if (n == 2) {
        if (s == "AB") {
            cout << "Alice" << '\n';
        }else {
            cout << "Bob" << '\n';
        }
        return;
    }

    if (s[s.size() - 1] == 'A' && (s[s.size() - 2] == 'A' || s[0] == 'A')) {
        cout << "Alice" << '\n';
    }else {
        ll cnt = 0;
        for (char c : s) {
            if (c == 'B') cnt++;
        }
        if (cnt == 1 && s[s.size() - 1] == 'B') {
            cout << "Alice" << '\n';
        }else {
            cout << "Bob" << '\n';
        }
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