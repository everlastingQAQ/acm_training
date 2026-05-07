#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    vector <vector <int> > pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        pos[v[i]].push_back(i);
    }
    bool ok = false;
    int t = -1;
    int st = -1, en = -1;
    for (int i = 1; i <= n; i++) {
        if (i == 1 && !pos[i].empty()) st = pos[i].back();
        if (i == n && !pos[i].empty()) en = pos[i].back();
        if (pos[i].empty()) {
            ok = true;
            t = i;
            break;
        }
    }

    if (ok) {
        cout << "?" << ' ' << t << ' ' << (t == 1 ? n : 1) << endl;
        int x;
        cin >> x;
        cout << "!" << ' ' << (x == 0 ? 'A' : 'B') << endl;
        return;
    }
    
    cout << "?" << ' ' << st << ' ' << en << endl;
    int x;
    cin >> x;
    cout << "?" << ' ' << en << ' ' << st << endl;
    int y;
    cin >> y;
    if (x == y && x >= n - 1) {
        cout << "!" << ' ' << 'B' << endl;
    }else {
        cout << "!" << ' ' << 'A' << endl;
    }
}

int main ()
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