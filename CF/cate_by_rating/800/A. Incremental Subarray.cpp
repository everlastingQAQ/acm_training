#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100003;
int a[MAXN];

int main ()
{
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        memset(a, 0, MAXN);
        bool is_legal = true;
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            cin >> a[j];
            cnt++;
            if (j != 0 && a[j] != a[j - 1] + 1) {
                cout << 1 << endl;
                is_legal = false;
                break;
            }
        }
        for (int k = 0; k < m - cnt; k++) {
            cin >> a[k];
        }
        if (is_legal == true) {
            cout << n - a[m - 1] + 1 << endl;
        }
    }

    return 0;
}