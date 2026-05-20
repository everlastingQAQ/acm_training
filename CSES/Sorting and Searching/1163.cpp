#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int x, n;
    cin >> x >> n;
    multiset <int> st1;
    set <int> st2;
    st2.insert(0);
    st2.insert(x);
    st1.insert(x);
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        auto l = (--st2.upper_bound(t));
        auto r = st2.upper_bound(t);
        int len = *r - *l;
        int x1 = *r - t;
        int x2 = t - *l;
        st1.insert(x1);
        st1.insert(x2);
        st1.erase(st1.find(len));
        st2.insert(t);
        cout << *st1.rbegin() << ' ';
    }
}   

int32_t main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 