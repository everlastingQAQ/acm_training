#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{   
    string s; cin >> s;
    int ans = 0;
    int n = s.size();
    vector <char> stk;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            cnt++;
            ans = max(ans, cnt);
            stk.push_back('(');
        }else {
            stk.pop_back();
            cnt--;
        }
    }

    cout << ans << '\n';
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