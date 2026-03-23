#include <bits/stdc++.h>
using namespace std;

mt19937 rng((unsigned)chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 你可以把这里改大一点，比如 100 / 1000
    int T = rnd(1, 1);
    cout << T << '\n';

    while (T--) {
        // 对拍时建议 n 不要太大，方便暴力跑
        int n = rnd(2, 8);
        cout << n << '\n';

        vector<int> a(n + 1), b(n + 1);

        int type = rnd(1, 7);

        if (type == 1) {
            // 完全随机
            for (int i = 1; i <= n; i++) {
                a[i] = rnd(1, n);
                b[i] = rnd(1, n);
            }
        }
        else if (type == 2) {
            // 全部相等 / 大量重复
            int x = rnd(1, n), y = rnd(1, n);
            for (int i = 1; i <= n; i++) {
                a[i] = x;
                b[i] = y;
            }
        }
        else if (type == 3) {
            // 一部分位置本来就相等
            for (int i = 1; i <= n; i++) {
                a[i] = rnd(1, n);
                if (rnd(0, 1)) b[i] = a[i];
                else b[i] = rnd(1, n);
            }
        }
        else if (type == 4) {
            // a 与 b 互相错位
            for (int i = 1; i <= n; i++) {
                a[i] = i;
                b[i] = (i % n) + 1;
            }
        }
        else if (type == 5) {
            // 交错构造
            for (int i = 1; i <= n; i++) {
                if (i & 1) {
                    a[i] = rnd(1, n);
                    b[i] = a[i];
                } else {
                    a[i] = rnd(1, n);
                    b[i] = rnd(1, n);
                }
            }
        }
        else if (type == 6) {
            // 值域很小，更容易出现重复链
            int lim = min(n, 3);
            for (int i = 1; i <= n; i++) {
                a[i] = rnd(1, lim);
                b[i] = rnd(1, lim);
            }
        }
        else {
            // 构造一些“后缀传播”感强的样例
            for (int i = 1; i <= n; i++) {
                a[i] = rnd(1, n);
                b[i] = rnd(1, n);
            }
            // 强行让后面几个位置重复
            int val1 = rnd(1, n), val2 = rnd(1, n);
            for (int i = max(1, n - 2); i <= n; i++) {
                if (rnd(0, 1)) a[i] = val1;
                if (rnd(0, 1)) b[i] = val2;
            }
        }

        for (int i = 1; i <= n; i++) {
            cout << a[i] << " \n"[i == n];
        }
        for (int i = 1; i <= n; i++) {
            cout << b[i] << " \n"[i == n];
        }
    }

    return 0;
}