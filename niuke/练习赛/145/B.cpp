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

    vector <string> s;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < s.size(); j++) {
            if (s[j] > s[j + 1] || j == s.size() - 1) {
                s.erase(j, 1);
                break;
            }
        }

        
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