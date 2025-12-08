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

    if (n % 4 == 0) {
        cout << 0 << '\n';
        return;
    }

    ll p = n;
    ll cnt = 0;
    while (p % 4 == 0) {
        p--;
        cnt++;
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