#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <array <int, 2> > v(n + 1);

    auto cal = [&] (string s) -> int {
        string ss = s.substr(0, 2);
        int t0 = stoll(ss);
        string ss1 = s.substr(3, 5);
        int t1 = stoll(ss1);
        string ss2 = s.substr(6, 8);
        int t2 = stoll(ss2);
        return t0 * 3600 + t1 * 60 + t2;
    };

    for (int i = 1; i <= n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        v[i][0] = cal(s1), v[i][1] = cal(s2);
    }    

    sort(v.begin() + 1, v.end(), [] (auto a, auto b) {
        if (a[0] != b[0]) return a[0] < b[0];
        else return a[1] < b[1];
    });

    vector <int> a(90000, 0);
    for (int i = 1; i <= n; i++) {
        a[v[i][0]] += 1;
        a[v[i][1] + 1] -= 1;
    }

    int ans = 1;
    for (int i = 1; i <= 90000; i++) {
        a[i] += a[i - 1];
        ans = max(ans, a[i]);
    }
    cout << ans << '\n';
}    
    
int main ()
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