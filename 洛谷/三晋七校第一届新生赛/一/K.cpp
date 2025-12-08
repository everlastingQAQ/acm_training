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
    string s;
    cin >> s;
    vector <ll> a(n);
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        if ((s[i] + cnt) % 2 == 1) {
            a[i] = 1;
            cnt++;
        }else {
            a[i] = 0;
            continue;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i];
    }

    return;
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