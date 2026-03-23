#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = (i64)1e4 + 7;

void solve ()
{
    string x;
    int n;
    cin >> x >> n;
    vector <int> cnt(10, 0);

    set <array <int, 2> > st;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        cnt[a]++;
        st.insert({a, b});
    }

    
}   
    
int main ()
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