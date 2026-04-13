#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int N = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;

bool vis[20000005];//这里如果用vector记录可能会被卡常

void solve ()
{
    ll n; cin >> n;
    if (vis[n]) {
        cout << "Yes" << '\n';
    }else {
        cout << "No" << '\n';
    }
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _ = 1;
    cin >> _;

    for (int i = 1; i < 4473; i++) {
        if (i * i > 2e7 + 2) break;
        for (int j = i; j < 4473; j++) {
            if (i * i + j * j > 2e7 + 2) break;
            vis[i * i + j * j] = true;
        }
    }   

    while (_--) {
        solve();
    }
    return 0;
}   