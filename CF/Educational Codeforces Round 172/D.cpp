#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	int n;
    cin >> n;
    vector <array <int, 3> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i][0] >> v[i][1];
        v[i][2] = i;
    }
    vector <array <int, 3> > vv;
    vv = v;

    vector <array <int, 2> > ans(n + 1, {-1, -1});
    sort(v.begin() + 1, v.end());
    multiset <int> st;
    int pre = 1;
    for (int i = 1; i <= n; i++) {
        pre = i;
        st.insert(v[i][1]);
        while (i < n && v[i][0] == v[i + 1][0]) {
            st.insert(v[i + 1][1]);
            i++;
        }
        for (int j = pre; j <= i; j++) {
            st.erase(st.find(v[j][1]));
            auto it = st.lower_bound(v[j][1]);
            if (it != st.end()) ans[v[j][2]][1] = *it;
            st.insert(v[j][1]);
        }
    }
    st.clear();

    sort(v.begin() + 1, v.end(), [] (auto a, auto b) {
        return a[1] > b[1];
    });
    pre = 1;
    for (int i = 1; i <= n; i++) {
        pre = i;
        st.insert(v[i][0]);
        while (i < n && v[i][1] == v[i + 1][1]) {
            st.insert(v[i + 1][0]);
            i++;
        }
        for (int j = pre; j <= i; j++) {
            st.erase(st.find(v[j][0]));
            auto it = st.upper_bound(v[j][0]);
            if (it != st.begin()) {
                it--;
                ans[v[j][2]][0] = *it;
            }
            st.insert(v[j][0]);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (ans[i][0] == -1 || ans[i][1] == -1) {
            cout << 0 << '\n';
        }else {
            cout << ans[i][1] - ans[i][0] - (vv[i][1] - vv[i][0]) << '\n';
        }
    }
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