#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
	int n;
    cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    if (n == 1) {
        cout << 1 << '\n';
        return;
    }else if (n == 2) {
        cout << abs(v[2] - v[1]) << '\n';
        return;
    }else if (n == 3) {

    } 

    sort(v.begin() + 1, v.end());
    multiset <int> st;
    for (int i = 2; i <= n; i += 2) {
        st.insert(v[i] - v[i - 1]);
    }

    if (n & 1) {
        int ans = 1e18;
        for (int i = 1; i <= n; i++) {
            vector <int> a = v;
            a.erase(a.begin() + i);
            vector <int> b;
            for (int j = 2; j <= n - 1; j += 2) {
                b.push_back(a[j] - a[j - 1]);
            }
            sort(b.begin(), b.end());
            ans = min(ans, b.back());
        }   
        cout << ans << '\n';
    }else {
        cout << *st.rbegin() << '\n';
    }
} 

int32_t main ()
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