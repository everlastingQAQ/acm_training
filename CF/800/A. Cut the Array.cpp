#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50;

int main ()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        int l = 1;
        int r = n - 1;
        
        int a[MAXN] = {};
        for (int j = 1; j <= n; j++) {
            cin >> a[j];
        }

        bool is_found = false;
        for (int k = 1; k < r; k++) {
            for (int p = r; p > k; p--) {
                int sum_l = 0;
                int sum_m = 0;
                int sum_r = 0;
                for (int j = 1; j <= k; j++) {
                    sum_l += a[j];
                }
                for (int j = k + 1; j <= p; j++) {
                    sum_m += a[j];
                }
                for (int j = p + 1; j <= n; j++) {
                    sum_r += a[j];
                }
                sum_l %= 3;
                sum_m %= 3;
                sum_r %= 3;

                if (sum_l == sum_m && sum_m == sum_r || (sum_l != sum_m && sum_l != sum_r && sum_m != sum_r)) {
                    cout << k << ' ' << p << endl;
                    is_found = true;
                    goto f;
                }
            }
        }
        if (is_found == false) {
            cout << 0 << ' ' << 0 << endl;
        }
        f:
    }

    return 0;
}