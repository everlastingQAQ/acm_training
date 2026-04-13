#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, k, l, r;
    cin >> n >> k >> l >> r;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    map <int, int> mp;
    set <int> st;

    for (int i = 1; i <= l; i++) {
        if (mp[v[i]]) {
            st.erase(mp[v[i]]);
        }
        mp[v[i]] = i;
        st.insert(i);
    }

    int lo = 1, ri = l;
    i64 ans = 0;
    
    while (ri <= n) {
        while (st.size() > k) {
            if (st.count(lo)) st.erase(lo);
            lo++;
        }
        if (ri - lo + 1 > r) {
            if (st.count(lo)) st.erase(lo);
            lo++;
        }

        if (st.size() == k && ri - lo + 1 >= l) {
            int cur = min((int)*st.begin(), ri - l + 1);
            ans += cur - lo + 1;
        }
        ri++;
        if (ri == n + 1) break;
        if (mp[v[ri]]) {
            st.erase(mp[v[ri]]);
        }
        mp[v[ri]] = ri;
        st.insert(ri);
    }

    cout << ans << '\n';
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 