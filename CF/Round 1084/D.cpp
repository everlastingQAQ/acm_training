#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector <int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector <int> a, b;
    for (int i = x; i < y; ++i) {
        a.push_back(v[i]);
    }
    for (int i = 0; i < x; ++i) {
        b.push_back(v[i]);
    }
    for (int i = y; i < n; ++i) {
        b.push_back(v[i]);
    }

    if (b.empty()) {
        int mn = 1e7;
        int pos = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] < mn) {
                pos = i;
                mn = v[i];
            }
        }
        for (int i = pos; i < n; i++) {
            cout << v[i] << ' ';
        }
        for (int i = 0; i < pos; i++) {
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }

    int mna = 1e9;
    int posa = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] < mna) {
            posa = i;
            mna = a[i];
        }
    }

    int mnb = 1e9;
    int posb = 0;
    for (int i = 0; i < b.size(); i++) {
        if (b[i] < mnb) {
            posb = i;
            mnb = b[i];
        }
    }

    int t = 0;
    while (t < b.size() && b[t] < mna) {
        cout << b[t] << ' ';
        t++;
    }
    for (int i = posa; i < a.size(); i++) {
        cout << a[i] << ' ';
    }
    for (int i = 0; i < posa; i++) {
        cout << a[i] << ' ';
    }
    for (int i = t; i < b.size(); i++) {
        cout << b[i] << ' ';
    }
    cout << '\n';
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