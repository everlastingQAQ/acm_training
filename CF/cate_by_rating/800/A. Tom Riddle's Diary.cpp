    #include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 1e6 + 5;
const double eps = 1e-5;
const ll mod = 998244353;
ll n;

void solve ()
{
    cin >> n;
    set <string> st;

    string s1;
    for (int i = 0; i < n; i++) {
        cin >> s1;
        if (st.count(s1)) {
            cout << "YES" << '\n';
        }else {
            cout << "NO" << '\n';
            st.insert(s1);
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