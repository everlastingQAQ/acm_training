#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    string s;
    cin >> s;
    int n = s.size();
    vector <array <int, 2> > cnt(26);
    for (int i = 0; i < 26; i++) {
        cnt[i][1] = i;
    }
    int mx = 0;
    for (auto c : s) {
        cnt[c - 'a'][0]++;
        mx = max(mx, cnt[c - 'a'][0]);
    }
    if (mx > (n + 1) / 2) {
        cout << "No\n";
        return;
    }

    sort(cnt.begin(), cnt.end(), [] (auto a, auto b) {
        return a[0] > b[0];
    });

    vector <char> ans(n + 1);
    int pos = 0;

    for (int i = 1; i <= n; i += 2) {
        while (cnt[pos][0] == 0) pos++;
        ans[i] = cnt[pos][1] + 'a';
        cnt[pos][0]--;
    }
    for (int i = 2; i <= n; i += 2) {
        while (cnt[pos][0] == 0) pos++;
        ans[i] = cnt[pos][1] + 'a';
        cnt[pos][0]--;
    }

    cout << "Yes\n";
    for (int i = 1; i <= n; i++) {
        cout << ans[i];
    }
    cout << "\n";
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