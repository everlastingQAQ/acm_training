#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using i128 = __int128_t;

static const int MAXP = 1000000; // sqrt(1e12)

/*---------------------------------------
  线性/埃氏筛都行，这里用普通筛出 1e6 内素数
---------------------------------------*/
vector<int> primes;

void init_primes() {
    vector<bool> is_prime(MAXP + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * 1LL * i <= MAXP; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAXP; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= MAXP; ++i) {
        if (is_prime[i]) primes.push_back(i);
    }
}

/*---------------------------------------
  判断 a^e <= limit 是否成立（防溢出）
---------------------------------------*/
bool pow_leq(int64 a, int e, int64 limit) {
    i128 cur = 1;
    for (int i = 0; i < e; ++i) {
        cur *= a;
        if (cur > (i128)limit) return false;
    }
    return true;
}

/*---------------------------------------
  求 floor(n^(1/k))
---------------------------------------*/
int64 floor_kth_root(int64 n, int k) {
    if (k == 1) return n;
    long double x = pow((long double)n, 1.0L / k);
    int64 r = (int64)x;
    while (pow_leq(r + 1, k, n)) ++r;
    while (r > 0 && !pow_leq(r, k, n)) --r;
    return r;
}

/*---------------------------------------
  把 n 转成 b 进制，检查是否是 (b,p)-tidy
  这里用于处理 k >= 2 的情况
---------------------------------------*/
bool is_tidy_in_base(int64 n, int64 b, int p) {
    vector<int64> dig;
    int64 x = n;
    while (x > 0) {
        dig.push_back(x % b);
        x /= b;
    }

    if ((int)dig.size() % p != 0) return false;

    for (int i = 0; i < (int)dig.size(); i += p) {
        for (int j = 1; j < p; ++j) {
            if (dig[i + j] != dig[i]) return false;
        }
    }
    return true;
}

/*---------------------------------------
  比较 R_p(b) = 1 + b + ... + b^(p-1) 与 target 的大小
  返回:
    -1: R_p(b) < target
     0: R_p(b) = target
     1: R_p(b) > target
---------------------------------------*/
int cmp_repunit(int64 b, int p, int64 target) {
    i128 sum = 1;
    i128 cur = 1;
    for (int i = 1; i < p; ++i) {
        cur *= b;
        sum += cur;
        if (sum > (i128)target) return 1;
    }
    if (sum == (i128)target) return 0;
    return -1;
}

/*---------------------------------------
  给定 m, p，判断是否存在 b >= 2 使得
    m = 1 + b + ... + b^(p-1)
  若存在返回 b，否则返回 -1
---------------------------------------*/
int64 find_base_for_repunit(int64 m, int p) {
    // R_p(b) > b^(p-1)，所以 b < m^(1/(p-1)) + 1
    int64 L = 2;
    int64 R = (p == 2 ? m - 1 : floor_kth_root(m, p - 1) + 1);
    if (R < 2) return -1;

    while (L <= R) {
        int64 mid = (L + R) >> 1;
        int c = cmp_repunit(mid, p, m);
        if (c == 0) return mid;
        if (c < 0) L = mid + 1;
        else R = mid - 1;
    }
    return -1;
}

/*---------------------------------------
  分解质因数
---------------------------------------*/
vector<pair<int64, int>> factorize(int64 n) {
    vector<pair<int64, int>> fac;
    for (int p : primes) {
        if (1LL * p * p > n) break;
        if (n % p == 0) {
            int c = 0;
            while (n % p == 0) {
                n /= p;
                ++c;
            }
            fac.push_back({p, c});
        }
    }
    if (n > 1) fac.push_back({n, 1});
    return fac;
}

/*---------------------------------------
  枚举所有因子
---------------------------------------*/
void gen_divisors_dfs(
    int idx,
    int64 cur,
    const vector<pair<int64, int>>& fac,
    vector<int64>& divs
) {
    if (idx == (int)fac.size()) {
        divs.push_back(cur);
        return;
    }
    auto [p, e] = fac[idx];
    int64 val = 1;
    for (int i = 0; i <= e; ++i) {
        gen_divisors_dfs(idx + 1, cur * val, fac, divs);
        val *= p;
    }
}

vector<int64> get_divisors(int64 n) {
    auto fac = factorize(n);
    vector<int64> divs;
    gen_divisors_dfs(0, 1, fac, divs);
    return divs;
}

/*---------------------------------------
  求 tidiness
---------------------------------------*/
int64 solve_one(int64 n) {
    if (n == 1) return 0;

    int max_p = 1;
    while (((i128)1 << max_p) <= (i128)n) ++max_p;
    // 实际 p 枚举到 max_p 即可（因为 2^(p-1) > n 就肯定不行）

    int64 ans = 0;

    // ----------------------------
    // Part 1: 处理 k >= 2
    // b <= n^(1/(2p-1))
    // ----------------------------
    for (int p = 2; p <= max_p; ++p) {
        if (((i128)1 << (p - 1)) > (i128)n) break;

        int exp = 2 * p - 1;
        int64 up = floor_kth_root(n, exp);
        for (int64 b = 2; b <= up; ++b) {
            if (is_tidy_in_base(n, b, p)) {
                ++ans;
            }
        }
    }

    // ----------------------------
    // Part 2: 处理 k = 1
    // n = d * R_p(b), 且 d < b
    // 通过枚举 n 的因子 m = R_p(b)
    // ----------------------------
    vector<int64> divisors = get_divisors(n);

    for (int64 m : divisors) {
        if (m < 3) continue; // R_p(b) 最小是 1+2=3

        for (int p = 2; p <= max_p; ++p) {
            // 最小的 R_p(2) = 2^p - 1
            i128 min_rep = ((i128)1 << p) - 1;
            if (min_rep > (i128)m) break;

            int64 b = find_base_for_repunit(m, p);
            if (b == -1) continue;

            int64 d = n / m;
            if (d < b) {
                ++ans;
            }
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init_primes();

    int T;
    cin >> T;
    while (T--) {
        int64 n;
        cin >> n;
        cout << solve_one(n) << '\n';
    }
    return 0;
}