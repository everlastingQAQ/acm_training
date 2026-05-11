#include <bits/stdc++.h>
using namespace std;
const int MAXN = 102;
int a[MAXN];

int main ()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        memset(a, 0, MAXN);
        for (int j = 1; j <= n; j++) {
            cin >> a[j];
        }

        int l = 1;
        int r = n;

        bool is_legal = true;
        for (int i = 1; i <= n; i++) {
            if (a[l] == i) {
                l++;
            }else if (a[r] == i) {
                r--;
            }else {
                is_legal = false;
                break;
            }
        }
        if (is_legal == true) {
            cout << "YES" << endl;
        }else {
            cout << "NO" << endl;
        }
    }

    return 0;
}