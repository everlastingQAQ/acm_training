#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    multiset <int> st1;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    auto cal = [&] () -> int {
        auto check = [&] (int md) -> bool {
            multiset <int> st;
            st = st1;
            auto it = st.begin();
            for (int i = md - 1; i >= 0; i--) {
                if (st.count(i)) {
                    st.erase(st.find(i));
                    continue;
                }
                auto it = st.lower_bound(2 * i + 1);
                if (it == st.end()) {
                    return false;
                }
                st.erase(it);
            }
            return true;
        };

        int lo = 0, ri = n + 1;
        int ans = 0;
        while (lo <= ri) {
            int mid = lo + ((ri - lo) >> 1);
            if (check(mid)) {
                lo = mid + 1;
                ans = mid;
            }else {
                ri = mid - 1;
            }
        }
        return ans;
    };

    for (int i = 1; i <= n; i++) {
        st1.insert(v[i]);
        int t = cal();
        cout << t << ' ';
    }
    cout << '\n';
}

int main ()
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