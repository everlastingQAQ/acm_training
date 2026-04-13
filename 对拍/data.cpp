#include <bits/stdc++.h>
using namespace std;

using u64 = unsigned long long;
using u128 = __uint128_t;
using i64 = long long;

static mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const i64 LIM = (i64)1e12;

// ---------------- Miller-Rabin for 64-bit ----------------
i64 mul_mod(i64 a, i64 b, i64 mod) {
    return (i64)((u128)a * (u128)b % (u128)mod);
}

i64 qpow_mod(i64 a, i64 e, i64 mod) {
    i64 r = 1 % mod;
    while (e) {
        if (e & 1) r = mul_mod(r, a, mod);
        a = mul_mod(a, a, mod);
        e >>= 1;
    }
    return r;
}

bool isPrime(i64 n) {
    if (n < 2) return false;
    for (i64 p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n % p == 0) return n == p;
    }

    i64 d = n - 1, s = 0;
    while ((d & 1) == 0) {
        d >>= 1;
        ++s;
    }

    // 这组底数对 64 位整数是确定正确的
    for (i64 a : {2, 3, 5, 7, 11, 13}) {
        if (a >= n) continue;
        i64 x = qpow_mod(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool comp = true;
        for (int r = 1; r < s; ++r) {
            x = mul_mod(x, x, n);
            if (x == n - 1) {
                comp = false;
                break;
            }
        }
        if (comp) return false;
    }
    return true;
}

// ---------------- Random helpers ----------------
i64 rnd(i64 l, i64 r) {
    uniform_int_distribution<i64> dist(l, r);
    return dist(rng);
}

i64 rand_odd_not_5(i64 l = 1, i64 r = LIM) {
    while (true) {
        i64 x = rnd(l, r);
        if ((x & 1) && x % 5 != 0) return x;
    }
}

i64 rand_bad(i64 l = 1, i64 r = LIM) {
    // 生成必然 NO 的数：含因子 2 或 5
    while (true) {
        i64 x = rnd(l, r);
        if (x % 2 == 0 || x % 5 == 0) return x;
    }
}

i64 rand_prime(i64 l = (i64)1e11, i64 r = LIM) {
    while (true) {
        i64 x = rnd(l, r);
        x |= 1; // odd
        if (x % 5 == 0) x += 2;
        while (x <= r) {
            if (isPrime(x)) return x;
            x += 2;
            if (x % 5 == 0) x += 2;
        }
    }
}

i64 rand_coprime10_primeish(i64 l = (i64)1e11, i64 r = LIM) {
    // 不强求一定是质数，但优先找大质数，找不到再退化
    for (int t = 0; t < 200; ++t) {
        i64 x = rand_prime(l, r);
        if (x % 2 && x % 5) return x;
    }
    return rand_odd_not_5(l, r);
}

// ---------------- Special cases ----------------
vector<i64> special_cases() {
    vector<i64> v = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 15, 17, 19, 21, 25, 27, 31,
        33, 35, 37, 39, 41, 45, 49, 55, 63, 77,
        81, 91, 99, 101, 111, 125, 127, 171, 181, 191,
        999, 1001, 1009, 1011, 1111, 9999, 10001, 99991,
        1000171,                 // 你前面讨论过的那类长循环节候选
        9999991, 99999931, 99999941,
        999999937LL,
        9999999967LL,
        99999999977LL,
        999999999989LL,          // 大数边界
        999999000059LL,
        (i64)1e12,
        (i64)1e12 - 1,
        (i64)1e12 - 3,
        (i64)1e12 - 5,
        (i64)1e12 - 7,
        999999999995LL,          // 5 的倍数
        999999999990LL,          // 2/5 的倍数
        999999999999LL
    };

    // 加一些 2^a, 5^b, 2^a*5^b, 以及乘上一点别的因子
    i64 x = 1;
    while (x <= LIM) {
        v.push_back(x);
        if (x > LIM / 2) break;
        x *= 2;
    }
    x = 1;
    while (x <= LIM) {
        v.push_back(x);
        if (x > LIM / 5) break;
        x *= 5;
    }
    for (int a = 0; a <= 20; ++a) {
        for (int b = 0; b <= 12; ++b) {
            long double y = 1;
            for (int i = 0; i < a; ++i) y *= 2;
            for (int i = 0; i < b; ++i) y *= 5;
            if (y > LIM) continue;
            i64 val = (i64)(y + 0.5);
            v.push_back(val);
            if (val <= LIM / 3) v.push_back(val * 3);
            if (val <= LIM / 7) v.push_back(val * 7);
            if (val <= LIM / 9) v.push_back(val * 9);
        }
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    vector<i64> ans;
    for (auto t : v) {
        if (1 <= t && t <= LIM) ans.push_back(t);
    }
    return ans;
}

// ---------------- Main generator ----------------
/*
用法：
1) 默认运行：生成 10000 组混合数据
   ./gen > data.in

2) 指定参数：
   ./gen T mode seed > data.in

其中：
T    = 数据组数
mode = 0 混合
       1 小数据（适合暴力）
       2 大量 NO（含 2/5 因子）
       3 大量 YES（与 10 互质）
       4 大质数压力
seed = 随机种子（可选）
*/
int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 10000;
    int mode = 0;
    unsigned long long seed = chrono::steady_clock::now().time_since_epoch().count();

    if (argc >= 2) T = atoi(argv[1]);
    if (argc >= 3) mode = atoi(argv[2]);
    if (argc >= 4) seed = strtoull(argv[3], nullptr, 10);

    rng.seed(seed);

    vector<i64> out;
    out.reserve(T);

    auto sp = special_cases();
    for (auto x : sp) {
        if ((int)out.size() < T) out.push_back(x);
    }

    while ((int)out.size() < T) {
        i64 x = 1;
        if (mode == 1) {
            // 小数据：方便你自己写暴力校验
            int typ = rnd(0, 4);
            if (typ == 0) x = rnd(1, 1000000);
            else if (typ == 1) x = rand_bad(1, 1000000);
            else if (typ == 2) x = rand_odd_not_5(1, 1000000);
            else if (typ == 3) x = rand_prime(2, 1000000);
            else x = rnd(1, 1000000);
        }
        else if (mode == 2) {
            // NO 数据为主
            int typ = rnd(0, 2);
            if (typ == 0) x = rand_bad();
            else if (typ == 1) {
                i64 y = rand_odd_not_5(1, (i64)1e11);
                if (y <= LIM / 10) x = y * 10;
                else x = rand_bad();
            } else {
                x = rnd(1, LIM);
                x -= x % 10;
                if (x == 0) x = 10;
            }
        }
        else if (mode == 3) {
            // YES 数据为主：与 10 互质
            int typ = rnd(0, 3);
            if (typ == 0) x = rand_odd_not_5();
            else if (typ == 1) x = rand_prime((i64)1e6, LIM);
            else if (typ == 2) x = rand_coprime10_primeish((i64)1e11, LIM);
            else {
                x = rnd(1, LIM);
                while ((x % 2 == 0) || (x % 5 == 0)) ++x;
                if (x > LIM) x = rand_odd_not_5();
            }
        }
        else if (mode == 4) {
            // 大质数压力
            int typ = rnd(0, 4);
            if (typ <= 2) x = rand_prime((i64)1e11, LIM);
            else if (typ == 3) x = rand_prime((i64)1e9, (i64)1e11);
            else x = rand_coprime10_primeish((i64)1e11, LIM);
        }
        else {
            // mode 0: 混合
            int typ = rnd(0, 9);
            if (typ == 0) x = rnd(1, 1000000);                 // 小数据
            else if (typ == 1) x = rand_bad();                 // NO
            else if (typ == 2) x = rand_odd_not_5();          // YES
            else if (typ == 3) x = rand_prime((i64)1e6, (i64)1e9);
            else if (typ == 4) x = rand_prime((i64)1e11, LIM);
            else if (typ == 5) x = rnd(LIM - 1000000, LIM);   // 接近上界
            else if (typ == 6) {
                i64 y = rand_odd_not_5(1, (i64)1e11);
                if (y <= LIM / 9) x = y * 9;
                else x = rand_odd_not_5();
            }
            else if (typ == 7) {
                i64 y = rand_odd_not_5(1, (i64)1e11);
                if (y <= LIM / 2) x = y * 2; // 强行变 NO
                else x = rand_bad();
            }
            else if (typ == 8) {
                // 造一些靠近 10^k 的数
                vector<i64> base = {
                    9LL, 99LL, 999LL, 9999LL, 99999LL, 999999LL,
                    9999999LL, 99999999LL, 999999999LL,
                    9999999999LL, 99999999999LL, 999999999999LL
                };
                x = base[rnd(0, (int)base.size() - 1)];
                i64 d = rnd(-1000, 1000);
                x += d;
                if (x < 1) x = 1;
                if (x > LIM) x = LIM;
            }
            else x = rnd(1, LIM);
        }

        if (1 <= x && x <= LIM) out.push_back(x);
    }

    // 可以打乱，让特殊数据不要总在最前面
    shuffle(out.begin(), out.end(), rng);

    cout << T << '\n';
    for (int i = 0; i < T; ++i) {
        cout << out[i] << '\n';
    }

    return 0;
}