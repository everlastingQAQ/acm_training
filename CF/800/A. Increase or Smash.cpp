#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int a[101] = {};
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            int t;
            cin >> t;
            if (a[t] == 0) {
                a[t] = 1;
            }else {
                continue;
            }
        }
        for (int k = 0; k < 101; k++) {
            if (a[k] == 1) {
                cnt++;
            }
        }
        cout << cnt * 2 - 1 << endl;
    }
    return 0;
}