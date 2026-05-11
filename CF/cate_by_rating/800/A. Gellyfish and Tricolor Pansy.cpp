#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 1e6 + 5;
const double eps = 1e-5;
const ll mod = 998244353;
ll a, b, c, d;

void solve ()
{
    cin >> a >> b >> c >> d;
    ll mnF = min(a, c);
    ll mnG = min(b, d);

    if (mnF >= mnG) {
        cout << "Gellyfish" << endl;
    }else {
        cout << "Flower" << endl;
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

