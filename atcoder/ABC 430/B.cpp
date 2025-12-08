#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define first fi
#define second se

ll n, m;

void solve ()
{
    cin >> n >> m;
    vector <string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    set<vector<string> > st;

    for (int i = 0; i < n - m + 1; i++) {
        for (int j = 0; j < n - m + 1; j++) {
            vector <string> v;
            for (int k = i; k < i + m; k++) {
                v.push_back(s[k].substr(j, m));
            }
            st.insert(v);
        }
    }

    cout << st.size() << '\n';
    
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}