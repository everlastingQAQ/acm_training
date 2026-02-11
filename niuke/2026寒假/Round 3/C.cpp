#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') v[i] = 1;
        else v[i] = 0;
    }

    vector <int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        if (i & 1) a[i] = 1;
        else a[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        if (i & 1) b[i] = 0;
        else b[i] = 1;
    }

    int ans = 1e11;

    auto cal = [&] (vector <int> v, vector <int> a) -> void {
        vector <array <int, 2> > p;

        for (int i = 1; i <= n; i++) {
            if (v[i] == 1 && a[i] == 0) p.push_back({i, 1});
            if (v[i] == 0 && a[i] == 1) p.push_back({i, 0});
        }

        vector <vector <array <int, 2> > > t(n + 1);
        deque <int> dq1, dq0;

        int cnt = 0;

        for (int i = 0; i < p.size(); i++) {
            auto [x, y] = p[i];
            if (y == 1) {
                if (dq0.empty()) {
                    t[cnt].push_back({x, y});
                    dq1.push_back(cnt);
                    cnt++;
                }else {
                    int temp = dq0.front();
                    t[temp].push_back({x, y});
                    dq0.pop_front();
                    dq1.push_back(temp);
                }
            }else if (y == 0) {
                if (dq1.empty()) {
                    t[cnt].push_back({x, y});
                    dq0.push_back(cnt);
                    cnt++;
                }else {
                    int temp = dq1.front();
                    t[temp].push_back({x, y});
                    dq1.pop_front();
                    dq0.push_back(temp);
                }
            }
        }

        ans = min(ans, cnt);
    };

    cal(v, a);
    cal(v, b);

    cout << ans << '\n';
}   
    
int32_t main ()
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

/*
  /\_/\
 (= ._.)
 / >  \>
*/