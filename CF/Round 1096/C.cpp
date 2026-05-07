#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <i64> v(n + 1);
    multiset <i64> st;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        st.insert(v[i]);
    }
    
    vector <i64> ans;
    auto it = st.begin();
    while (it != st.end()) {
        if (*it % 6 == 0) {
            ans.push_back(*it);
            it = st.erase(it);
        }else {
            it++;
        }
    }
    it = st.begin();
    while (it != st.end()) {
        if (*it % 3 == 0) {
            ans.push_back(*it);
            it = st.erase(it);
        }else {
            it++;
        }
    }
    it = st.begin();
    while (it != st.end()) {
        if (*it % 2 != 0) {
            ans.push_back(*it);
            it = st.erase(it);
        }else {
            it++;
        }
    }
    it = st.begin();
    while (it != st.end()) {
        if (*it % 2 == 0) {
            ans.push_back(*it);
            it = st.erase(it);
        }else {
            it++;
        }
    }
    for (auto x : ans) {
        cout << x << ' ';
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