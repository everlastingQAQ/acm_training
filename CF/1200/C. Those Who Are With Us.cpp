#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e3 + 5;
int a[MAXN][MAXN];
set <int> c;
set <int> d;
int rec[MAXN][2];

int cmp (int a1, int b1)
{
    return a1 > b1;
}

void solve ()
{
    int n, m;
    cin >> n >> m;

    memset(a, 0, sizeof(a));
    memset(rec, 0, sizeof(rec));
    c.clear();
    d.clear();

    int mx = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            mx = max(mx, a[i][j]);
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == mx) {
                rec[cnt][0] = i;
                rec[cnt][1] = j;
                cnt++;
            }
        }
    }


    for (int i = 0; i < cnt; i++) {
        c.insert(rec[i][0]);
    }

    for (int i = 0; i < cnt; i++) {
        d.insert(rec[i][1]);
    }

    bool FOUND = false;
    for (auto it = c.begin(); it != c.end(); it++) {
        for (auto its = d.begin(); its != d.end(); its++) {
            bool found = true;
            for (int i = 0; i < cnt; i++) {
                if (rec[i][0] != *it && rec[i][1] != *its) {
                    found = false;
                    break;
                }
            }
            if (found) {
                FOUND = true;
                break;
            }
        } 
        if (FOUND) {
            break;
        }  
    }

    if (FOUND) {
        cout << mx - 1 << endl;
    }else {
        cout << mx << endl;
    }
   
}

int main ()
{
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int _ = 1;
	cin >> _;

    while (_--) {
        solve();
    }

    return 0;
}