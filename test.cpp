#include <bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937_64 rng;

ll rnd(ll l, ll r) {
    return uniform_int_distribution<ll>(l, r)(rng);
}

// 根据指定的 prefix mod 序列反推 a
// pre[0] = 0, pre[i] = sum a[1..i] % r
vector<ll> build_a_from_pre(const vector<ll>& pre, ll r) {
    int n = (int)pre.size() - 1;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = (pre[i] - pre[i - 1] + r) % r;
    }
    return a;
}

void print_case(int n, ll r, const vector<ll>& a, const vector<ll>& c) {
    cout << n << ' ' << r << '\n';

    for (int i = 1; i <= n; i++) {
        cout << a[i] << " \n"[i == n];
    }

    for (int i = 1; i <= n; i++) {
        cout << c[i] << " \n"[i == n];
    }
}

vector<ll> gen_cost(int n, int mode) {
    vector<ll> c(n + 1);

    for (int i = 1; i <= n; i++) {
        if (mode == 0) {
            // 普通随机
            c[i] = rnd(0, 20);
        } else if (mode == 1) {
            // 极端大小混合
            c[i] = rnd(0, 1) ? rnd(0, 5) : rnd(1000000000LL - 10, 1000000000LL);
        } else if (mode == 2) {
            // 递增/递减混合，卡贪心感觉
            c[i] = (i % 2 ? i : n - i + 1);
        } else {
            // 大量 0 成本
            c[i] = rnd(0, 3) == 0 ? 0 : rnd(1, 100);
        }
    }

    return c;
}

void gen_one_case() {
    int mode = rnd(0, 7);

    int n;
    ll r;
    vector<ll> a, c;

    if (mode == 0) {
        // 完全随机小数据，适合暴力对拍
        n = rnd(1, 10);
        r = rnd(2, 8);

        a.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            a[i] = rnd(0, r - 1);
        }

        c = gen_cost(n, rnd(0, 3));
    } else if (mode == 1) {
        // r = 2，最容易出边界问题
        n = rnd(1, 20);
        r = 2;

        a.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            a[i] = rnd(0, 1);
        }

        c = gen_cost(n, rnd(0, 3));
    } else if (mode == 2) {
        // r = 3 / 4，前缀余数覆盖全部
        r = rnd(3, 4);
        n = rnd((int)r, 20);

        vector<ll> pre(n + 1);
        pre[0] = 0;

        // 先强行让前面覆盖所有余数
        vector<ll> vals;
        for (ll x = 0; x < r; x++) vals.push_back(x);
        shuffle(vals.begin(), vals.end(), rng);

        for (int i = 1; i <= min<int>(n, r); i++) {
            pre[i] = vals[i - 1];
        }

        for (int i = r + 1; i <= n; i++) {
            pre[i] = rnd(0, r - 1);
        }

        a = build_a_from_pre(pre, r);
        c = gen_cost(n, rnd(0, 3));
    } else if (mode == 3) {
        // 大量 prefix sum % r == 0
        n = rnd(1, 20);
        r = rnd(2, 8);

        vector<ll> pre(n + 1);
        pre[0] = 0;

        for (int i = 1; i <= n; i++) {
            if (rnd(0, 2) == 0) pre[i] = 0;
            else pre[i] = rnd(0, r - 1);
        }

        a = build_a_from_pre(pre, r);
        c = gen_cost(n, rnd(0, 3));
    } else if (mode == 4) {
        // r 很大，通常 st.size() != r，卡“不建线段树”的分支
        n = rnd(1, 30);
        r = rnd(100, 1000000000LL);

        a.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            a[i] = rnd(0, r - 1);
        }

        c = gen_cost(n, rnd(0, 3));
    } else if (mode == 5) {
        // 全 0，最朴素但很能卡初始化 / nxt[0]
        n = rnd(1, 20);
        r = rnd(2, 10);

        a.assign(n + 1, 0);
        c = gen_cost(n, rnd(0, 3));
    } else if (mode == 6) {
        // 前缀余数循环：0,1,2,...,r-1,0,1...
        r = rnd(2, 8);
        n = rnd(1, 30);

        vector<ll> pre(n + 1);
        pre[0] = 0;

        for (int i = 1; i <= n; i++) {
            pre[i] = i % r;
        }

        a = build_a_from_pre(pre, r);
        c = gen_cost(n, rnd(0, 3));
    } else {
        // 手搓一点“局部覆盖全部余数”的结构
        r = rnd(3, 8);
        n = rnd((int)r + 1, 30);

        vector<ll> pre(n + 1);
        pre[0] = 0;

        int pos = 1;
        while (pos <= n) {
            vector<ll> vals;
            for (ll x = 0; x < r; x++) vals.push_back(x);
            shuffle(vals.begin(), vals.end(), rng);

            for (ll x : vals) {
                if (pos > n) break;
                pre[pos++] = x;
            }
        }

        a = build_a_from_pre(pre, r);
        c = gen_cost(n, rnd(0, 3));
    }

    print_case(n, r, a, c);
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned long long seed;

    if (argc >= 2) {
        seed = stoull(argv[1]);
    } else {
        seed = chrono::steady_clock::now().time_since_epoch().count();
    }

    rng.seed(seed);

    // 对拍建议 T 开大一点，但 n 保持小
    int T = 1000;

    cout << T << '\n';
    while (T--) {
        gen_one_case();
    }

    cerr << "seed = " << seed << '\n';

    return 0;
}