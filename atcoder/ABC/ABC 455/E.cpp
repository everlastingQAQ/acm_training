#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    string s;
    cin >> n >> s;
    map <int, int> mpa, mpb, mpc;
    map <array <int, 2>, int> mp;

    s = ' ' + s;
    mpa[0] = mpb[0] = mpc[0] = mp[{0, 0}] = 1;
    vector <int> pa(n + 1), pb(n + 1), pc(n + 1);

    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        pa[i] = pa[i - 1] + (s[i] == 'A');
        pb[i] = pb[i - 1] + (s[i] == 'B');
        pc[i] = pc[i - 1] + (s[i] == 'C');
        
        int a = pa[i] - pb[i];
        int b = pa[i] - pc[i];
        int c = pb[i] - pc[i];
        cnt += mpa[a] + mpb[b] + mpc[c] - 2 * mp[{a, c}];

        mpa[a]++;
        mpb[b]++;
        mpc[c]++;
        mp[{a, c}]++;
    }

    cout << n * (n + 1) / 2 - cnt << '\n';
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