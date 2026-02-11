#include <bits/stdc++.h>
using namespace std;
#define int long long

struct point {
    int x, y;
};

void solve ()
{
    int n;
    cin >> n;
    vector <vector <char> > v(n + 1, vector <char> (n + 1));
    vector <point> p;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v[i][j];
            if (v[i][j] == '*') {
                p.push_back({i, j});
            }
        }
    }

    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (p[i].x == p[j].x) cnt1++;
            if (p[i].y == p[j].y) cnt2++; 
        }
    }

    if (cnt1 > cnt2) {
        point t;
        for (int i = 0; i < 4; i++) {
            int cnt = 0;
            for (int j = 0; j < 4; j++) {
                if (p[i].x != p[j].x) {
                    cnt++;
                }
            }
            if (cnt == 3) t = p[i];
        }

        int tt = 0;
        for (int i = 0; i < 4; i++) {
            if (p[i].x == t.x && p[i].y == t.y) continue;
            tt += p[i].y;
        }
        if (tt / 3 == t.y) {
            cout << "T\n";
        }else {
            cout << "L\n";
        }
    }else {
        point t;
        for (int i = 0; i < 4; i++) {
            int cnt = 0;
            for (int j = 0; j < 4; j++) {
                if (p[i].y != p[j].y) {
                    cnt++;
                }
            }
            if (cnt == 3) t = p[i];
        }

        int tt = 0;
        for (int i = 0; i < 4; i++) {
            if (p[i].x == t.x && p[i].y == t.y) continue;
            tt += p[i].x;
        }

        if (tt / 3 == t.x) {
            cout << "T\n";
        }else {
            cout << "L\n";
        }
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

/*
  /\_/\
 (= ._.)
 / >  \>
*/