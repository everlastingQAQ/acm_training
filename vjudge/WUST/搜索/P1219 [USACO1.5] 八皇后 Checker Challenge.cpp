#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 998244353;

ll n;
ll num = 0;
vector <ll> ans;
bool b[110];
bool c[110];
bool d[110];

void print ()
{
    for (auto x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
}

void dfs (ll i)
{
    if (i == n) {
        if (num < 3) {
            print();
        }
        num++;
        return;
    }

    for (int j = 1; j <= n; j++) {
        if (b[j] == 0 && c[i + j] == 0 && d[n + i - j] == 0) {
            ans.push_back(j);
            b[j] = 1;
            c[i + j] = 1;
            d[n + i - j] = 1;
            dfs(i + 1);
            b[j] = 0;
            c[i + j] = 0;
            d[n + i - j] = 0;
            ans.pop_back();
        }
    }
}

void solve ()
{
    cin >> n;
    dfs(0);
    cout << num << '\n';
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