#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#define int long long
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve ()
{
    int n;
    cin >> n;
    ordered_set <pair <int, int> > st;
    int id = 1;
    int inf = (1LL << 60);
    while (n--) {
        int op, x;
        cin >> op >> x;
        if (op == 1) {
            st.insert({x, id++});
        }else if (op == 2) {
            auto it = st.lower_bound({x, -inf});
            if (it != st.end() && it->first == x) {
                st.erase(it);
            }
        }else if (op == 3) {
            int pos = st.order_of_key({x, -inf}) + 1;
            cout << pos << '\n';
        }else if (op == 4) {
            auto it = st.find_by_order(x - 1);
            cout << it->first << '\n';
        }else if (op == 5) {
            auto it = st.lower_bound({x, -inf});
            it--;
            cout << it->first << '\n';
        }else {
            auto it = st.lower_bound({x, inf});
            cout << it->first << '\n';
        }
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