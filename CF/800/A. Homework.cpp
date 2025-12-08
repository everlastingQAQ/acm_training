#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 5;
int a[MAXN];

void solve ()
{
    int n, m;
    string a, b, c;
    cin >> n >> a >> m >> b >> c;
    for (int i = 0; i < m; i++) {
        if (c[i] == 'D') {
            a.push_back(b[i]);
        }else {
            a = b[i] + a;
        }
    }
    cout << a << endl;
}

int main ()
{
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}