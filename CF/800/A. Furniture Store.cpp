#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10000;
int a[MAXN];

void solve ()
{
    int n;
    cin >> n;

    memset(a, 0, MAXN);
    set <int> b;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[j] > a[i]) {
                b.insert(j);
            }
        }
    }

    cout << b.size() << endl;
    
    for (int c : b) {
        cout << c << ' ';
    }

    cout << endl;
}

int main ()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }

    return 0;
}