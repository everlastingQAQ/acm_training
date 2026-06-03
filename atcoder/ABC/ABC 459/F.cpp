#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node {
    int len, sum;
    node operator + (const node &st) const {
        return node{st.len + len, st.sum + sum};
    }
};

int Floor (int a, int b) {
    if (a >= 0) return a / b;
    return -((-a + b - 1) / b);

}

int Ceil (int a, int b) {
    return -Floor(-a, b);
}

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i] -= i;
    }

    vector <node> st;
    for (int i = 1; i <= n; i++) {
        st.push_back({1, v[i]});
        while (st.size() >= 2) {
            node s = st.back();
            node t = st[st.size() - 2];
            int smn = Floor(s.sum, s.len);
            int tmx = Ceil(t.sum, t.len);
            if (smn < tmx) {
                st.pop_back();
                st.pop_back();
                st.push_back({s + t});
            }else {
                break;
            }
        }
    }

    vector <int> f(n + 1);
    int pos = 1;

    for (auto x : st) {
        int mn = Floor(x.sum, x.len);
        int cmx = x.sum - mn * x.len;
        int cmn = x.len - cmx;
        for (int i = 1; i <= cmn; i++) {
            f[pos++] = mn;
        }
        for (int i = 1; i <= cmx; i++) {
            f[pos++] = mn + 1;
        }
    }

    int ans = 0;
    int pv = 0, pf = 0;
    for (int i = 1; i <= n - 1; i++) {
        pv += v[i];
        pf += f[i];
        ans += pv - pf;
    }

    cout << ans << '\n';
}   
    
int32_t main ()
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