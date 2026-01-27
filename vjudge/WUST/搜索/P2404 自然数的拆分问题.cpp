#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

ll n;
vector <ll> v(15);

void print(ll pos)
{
    if (pos == 2) {
        return;
    }
    for (int i = 1; i < pos; i++) {
        if (i == 1) {
            cout << v[i];
        }else {
            cout << '+' << v[i];
        }
    }
    cout << '\n';
    return;
}

void dfs(ll ori, ll sum, ll pos)
{
    if (sum == n) {
        print(pos);
        return;
    }

    for (int i = ori; i <= n - sum; i++) {
        v[pos] = i;
        sum += i;
        pos++;
        dfs(i, sum, pos);
        sum -= i;
        pos--;
    }
}

void solve ()
{
    cin >> n;
    dfs(1LL, 0LL, 1LL);
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