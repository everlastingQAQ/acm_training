#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18;

void solve ()
{
    int h, w, t;
    cin >> h >> w >> t;
    vector <vector <char> > e(h + 1, vector <char> (w + 1));
    using arr2 = array <int, 2>;
    using arr3 = array <int, 3>;
    int n = 2;
    arr2 st, en;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> e[i][j];
            if (e[i][j] == 'S') st[0] = i, st[1] = j;
            else if (e[i][j] == 'G') en[0] = i, en[1] = j;
            else if (e[i][j] == 'o') n++; 
        }
    }

    map <arr2, int> mp;
    vector <arr2> v(n + 1);
    v[0] = st;
    v[n] = en;
    int cnt = 1;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (e[i][j] == 'o') v[cnt] = {i, j}, mp[{i, j}] = cnt++; 
        }
    }

    vector <vector <int> > dis(n + 1);
    auto bfs = [&] (int st) -> vector <int> {
        queue <arr3> q;
        vector <int> dis(n + 1);
        int cur = 0;
    };
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