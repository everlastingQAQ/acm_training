#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    queue <int> q;
    vector <int> stk;
    vector <int> aq;
    vector <int> as;

    for (int i = 1; i <= m; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int t;
            cin >> t;
            q.push(t);
            stk.push_back(t);
        }else {
            int t = q.front();
            aq.push_back(t);
            q.pop();
            t = stk.back();
            as.push_back(t);
            stk.pop_back();
        }
    }

    if (v == as && v == aq) {
        cout << "both\n";
    }else if (v == as) {
        cout << "stack\n";
    }else if (v == aq) {
        cout << "queue\n";
    }else {
        cout << -1 << '\n';
    }
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
