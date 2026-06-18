#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m, d;
    cin >> n >> m >> d;
    set <array <int, 2> > st;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        st.insert({t, i});
    }

    vector <int> ans(n + 1);
    int day = 1;
    while (!st.empty()) {
        int cur = 0;
        while (cur <= m) {
            auto it = st.lower_bound({cur, -1});
            if (it != st.end()) {
                auto [x, y] = *it;
                ans[y] = day;
                st.erase(it);
                cur = x + d + 1;
            }else break;
        }
        day++;
    }

    cout << day - 1 << '\n';
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int32_t main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}