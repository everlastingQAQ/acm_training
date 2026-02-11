#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{   
    int n; cin >> n;
    string s, t; cin >> s >> t;
    s = ' ' + s;
    t = ' ' + t;
    vector <array <int, 2> > ans1, ans2;

    auto cal = [&] (string &s, vector <array <int, 2> > &ans) -> void {
        auto flip = [&] (int l, int r) -> void {
            for (int i = l; i <= r; i++) {
                s[i] = (s[i] == '0' ? '1' : '0');
            }
        };
        
        int idx = 1;
        while (idx <= n) {
            if (s[idx] == '0') {
                idx++;
            }else if (s[idx] == '1') {
                int l = idx;
                while (idx <= n && s[idx] == '1') {
                    idx++;
                }
                if (idx == l + 1) {
                    if (l + 2 <= n) {
                        if (s[l + 2] == '1') {//101->010
                            ans.push_back({l, l + 2});
                            flip(l, l + 2);
                        }else {//100->000
                            ans.push_back({l + 1, l + 2});
                            flip(l + 1, l + 2);
                            ans.push_back({l, l + 2});
                            flip(l, l + 2);
                        }
                    }else {
                        if (s[l - 2] == '1') {//101->010
                            ans.push_back({l - 2, l});
                            flip(l - 2, l);
                            idx = l - 2;
                        }else {//001->000
                            ans.push_back({l - 2, l - 1});
                            flip(l - 2, l - 1);
                            ans.push_back({l - 2, l});
                            flip(l - 2, l);
                            idx = l - 2;
                        }
                    }
                }else {
                    ans.push_back({l, idx - 1});
                    flip(l, idx - 1);
                }
            }
        }
    };

    cal(s, ans1);
    cal(t, ans2);
    ranges::reverse(ans2);

    cout << ans1.size() + ans2.size() << '\n';
    for (auto [x, y] : ans1) {
        cout << x << ' ' << y << '\n';
    }
    for (auto [x, y] : ans2) {
        cout << x << ' ' << y << '\n';
    }
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