#include <bits/stdc++.h>
using namespace std;
#define int long long
#define arr2 array <int, 2> 

void solve ()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vector <arr2> x (n), y (n), z (n);

    for (int i = 0; i < n; i ++) {
        cin >> x[i][0] >> y[i][0] >> z[i][0] >> x[i][1] >> y[i][1] >> z[i][1];
        if (x[i][0] > x[i][1]) {
            swap (x[i][0], x[i][1]);
        }
        if (y[i][0] > y[i][1]) {
            swap (y[i][0], y[i][1]);
        }
        if (z[i][0] > z[i][1]) {
            swap (z[i][0], z[i][1]);
        }
    }
    

    sort (x.begin(), x.end());
    sort (y.begin(), y.end());
    sort (z.begin(), z.end());

    int ans1 = 0;
    priority_queue <int, vector <int>, greater <int> > pq;

    int mx1 = 0, cur = 0;
    for (int i = 0; i < n; i ++) {
        cur++;
        auto [x1, x2] = x[i];
        while (pq.size()) {
            int xx = pq.top();
            if (xx < x1) {
                pq.pop();
                cur--;
            }
            else break;
        }

        mx1 = max (mx1, cur);
        pq.push(x2);
    }

    while (pq.size()) pq.pop();

    int mx2 = 0;
    cur = 0;
    for (int i = 0; i < n; i ++) {
        cur++;
        auto [y1, y2] = y[i];
        while (pq.size()) {
            int yy = pq.top();
            if (yy < y1) {
                pq.pop();
                cur--;
            }
            else break;
        }

        mx2 = max (mx2, cur);
        pq.push(y2);
    }    

    while (pq.size()) pq.pop();

    int mx3 = 0;
    cur = 0;
    for (int i = 0; i < n; i ++) {
        cur++;
        auto [z1, z2] = z[i];
        while (pq.size()) {
            int zz = pq.top();
            if (zz < z1) {
                pq.pop();
                cur--;
            }
            else break;
        }

        mx3 = max (mx3, cur);
        pq.push(z2);
    }     

    cout << max ({mx1, mx2, mx3}) << '\n';
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