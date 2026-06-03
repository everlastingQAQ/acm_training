#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#define int long long
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve ()
{
    int n, k;
    // cin >> n >> k;
    cin >> n;
    k = 1;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    ordered_set <int> st;
    for (int i = 1; i <= n; i++) {
        st.insert(i);
    }
    int pos = 0;
    for (int i = n; i >= 1; i--) {
        pos = (pos + k) % i;
        auto it = st.find_by_order(pos);
        cout << *it << ' ';
        st.erase(it);
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