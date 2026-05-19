#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    string s;
    cin >> n >> s;
    s = ' ' + s;
    vector <map <char, int> > dp1(n + 1);
    for (int i = 1; i <= n; i++) {
        dp1[i]['q'] += dp1[i - 1]['q'];
        dp1[i]['c'] += dp1[i - 1]['c'];
        dp1[i]['a'] += dp1[i - 1]['a'];
        dp1[i]['y'] += dp1[i - 1]['y'];
        if (s[i] == 'q') {
            dp1[i]['q']++;
        }else if (s[i] == 'c') {
            dp1[i]['c'] += dp1[i]['q'];
        }else if (s[i] == 'a') {
            dp1[i]['a'] += dp1[i]['c'];
        }else if (s[i] == 'y') {
            dp1[i]['y'] += dp1[i]['a'];
        }
    }
    int a1 = dp1[n]['y'];

    vector <map <char, int> > dp2(n + 1);
    for (int i = 1; i <= n; i++) {
        dp2[i]['q'] += dp2[i - 1]['q'];
        dp2[i]['c'] += dp2[i - 1]['c'];
        dp2[i]['j'] += dp2[i - 1]['j'];
        dp2[i]['k'] += dp2[i - 1]['k'];
        if (s[i] == 'q') {
            dp2[i]['q']++;
        }else if (s[i] == 'c') {
            dp2[i]['c'] += dp2[i]['q'];
        }else if (s[i] == 'j') {
            dp2[i]['j'] += dp2[i]['c'];
            dp2[i]['k'] += dp2[i - 1]['j'];
        }
    }

    int a2 = dp2[n]['k'];
    if (a1 > a2) {
        cout << "qcay\n";
    }else {
        cout << "qcjj\n";
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