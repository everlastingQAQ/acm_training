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
 
ll n, m;

void solve ()
{   
    cin >> n >> m;
    ll t = lcm(n, m);
    string sa, sb, s1, s2;
    cin >> sa >> sb;
    if (n != m) {
        for (int i = 0; i < t / n; i++) {
            s1 += sa;
        }
        for (int i = 0; i < t / m; i++) {
            s2 += sb;
        }
    }else {
        t = m;
        s1 = sa;
        s2 = sb;
    }

    int found = 0;
    ll pos = 0;
    for (; pos < t; pos++) {
        if (s1[pos] > s2[pos]) {
            found = 1;
            break;
        }else if (s1[pos] < s2[pos]) {
            found = 2;
            break;
        }
    }

    cout << t << '\n';
    vector <int> ans;

    if (found == 2) {
        swap(s1, s2);
    }

    for (int i = t - 1; i >= 0; i--) {
        int a = s1[i] - '0';
        int b = s2[i] - '0';
        if (a - b >= 0) {
            ans.push_back(a - b);
        }else {
            ans.push_back(a + 10 - b);
            if (i == 0) break;
            ll p = i - 1;
            while (p >= 0 && s1[p] == '0') {
                s1[p] = '9';
                p--;
            }
            if (p >= 0) {
                s1[p] = char(s1[p] - 1);
            }
        }
    }

    if (found == 2) {   
        for (int i = 0; i < ans.size(); i++) {
            ans[i] = 9 - (int)ans[i];
        }
    }

    reverse(ans.begin(), ans.end());
    
    for (int x : ans) {
        cout << x;
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