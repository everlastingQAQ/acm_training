#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 1e6 + 5;
const double eps = 1e-5;
const ll mod = 998244353;

ll n;
string s;

bool cmp (int a1, int b1)
{
    return a1 > b1;
}

ll power(ll x)
{
    ll ans = 1;
    for (int i = 0; i < x; i++) {
        ans *= 2;
        ans %= mod;
    }
    return ans;
}

void solve ()
{
    cin >> n >> s;
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            cnt++;
        }
    }

    if (cnt % 2 == 1) {
        cout << 0 << endl;
    }else {
        cout << 2 << endl;
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