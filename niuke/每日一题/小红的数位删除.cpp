#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int a, b;
    cin >> a >> b;
    set <array <int, 2> > st;
    queue <array <int, 3> > q;
    q.push({0, a, b});

    while (q.size()) {
        auto [cnt, x, y] = q.front();
        q.pop();
        if (!(x % y) || !(y % x)) {
            cout << cnt << '\n';
            return;
        }
        for (int i = 1; i <= x; i *= 10) {
            int xx = x / (i * 10) * i + x % i;
            if (xx == 0) continue;
            if (st.count({xx, y})) continue;
            st.insert({xx, y});
            q.push({cnt + 1, xx, y});
        }
        for (int i = 1; i <= y; i *= 10) {
            int yy = y / (i * 10) * i + y % i;
            if (yy == 0) continue;
            if (st.count({x, yy})) continue;
            st.insert({x, yy});
            q.push({cnt + 1, x, yy});
        }
    }

    cout << -1 << '\n';
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

/*
  /\_/\
 (= ._.)
 / >  \>
*/