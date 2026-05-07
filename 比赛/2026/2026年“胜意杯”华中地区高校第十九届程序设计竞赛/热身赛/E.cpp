#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll = long long;
using boost::multiprecision::cpp_int;

const ll INF = 1000000001LL;   // n <= 1e9，计数超过它就截断
const int ENUM_LIMIT = 60000;   // 小于这个数量就直接枚举排序

ll cap_add(ll a, ll b) {
    if (a >= INF || b >= INF) return INF;
    if (a + b >= INF) return INF;
    return a + b;
}

ll cap_mul_add(ll a, ll b, ll c) {
    __int128 v = (__int128)a + (__int128)b * c;
    if (v >= INF) return INF;
    return (ll)v;
}

/* ---------------- vector<long long> 哈希 ---------------- */

struct VecHash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }

    size_t operator()(const vector<ll>& v) const {
        uint64_t h = 0;
        for (ll x : v) {
            h ^= splitmix64((uint64_t)x + 0x9e3779b97f4a7c15ULL + (h << 6) + (h >> 2));
        }
        return (size_t)h;
    }
};

/* 
   给定生成部分前缀 b[0..m-1]，
   统计下一个生成项 b[m] 的所有可能值及其数量。

   右往左拆递推式：
   b_t = sum c_j * s_{j+t}
   每次往左加入一个初值 x 和一个系数 c。
*/
struct DistSolver {
    int m;
    vector<ll> prefix;

    unordered_map<vector<ll>, map<ll, ll>, VecHash> memo;

    DistSolver(const vector<ll>& p) : prefix(p) {
        m = (int)p.size();
        memo.reserve(200000);
    }

    vector<ll> make_key(const vector<ll>& R, const vector<ll>& N) {
        vector<ll> key;
        key.reserve(R.size() + N.size());
        for (ll x : R) key.push_back(x);
        for (ll x : N) key.push_back(x);
        return key;
    }

    const map<ll, ll>& dfs(const vector<ll>& R, const vector<ll>& N) {
        vector<ll> key = make_key(R, N);
        auto it = memo.find(key);
        if (it != memo.end()) return it->second;

        map<ll, ll> res;

        bool zero = true;
        for (ll x : R) {
            if (x != 0) {
                zero = false;
                break;
            }
        }

        if (zero) {
            res[0] = 1;
            auto ret = memo.emplace(move(key), move(res));
            return ret.first->second;
        }

        if (R[0] <= 0) {
            auto ret = memo.emplace(move(key), move(res));
            return ret.first->second;
        }

        for (ll x = 1; x <= R[0]; x++) {
            ll maxc = R[0] / x;

            for (int i = 1; i < m; i++) {
                maxc = min(maxc, R[i] / N[i - 1]);
                if (maxc == 0) break;
            }

            for (ll c = 1; c <= maxc; c++) {
                vector<ll> nR(m);
                nR[0] = R[0] - c * x;
                for (int i = 1; i < m; i++) {
                    nR[i] = R[i] - c * N[i - 1];
                }

                vector<ll> nN(m);
                nN[0] = x;
                for (int i = 1; i < m; i++) {
                    nN[i] = N[i - 1];
                }

                const auto& sub = dfs(nR, nN);
                ll add = c * N[m - 1];

                for (auto [v, cnt] : sub) {
                    __int128 nv128 = (__int128)v + add;
                    ll nv = (nv128 > LLONG_MAX ? LLONG_MAX : (ll)nv128);

                    ll &cur = res[nv];
                    cur = cap_add(cur, cnt);
                }
            }
        }

        auto ret = memo.emplace(move(key), move(res));
        return ret.first->second;
    }

    const map<ll, ll>& solve() {
        vector<ll> R = prefix;
        vector<ll> N = prefix;
        return dfs(R, N);
    }
};

/* ---------------- 显式枚举某个前缀下的所有递推式 ---------------- */

struct Candidate {
    vector<int> c;
    vector<int> a;
    vector<cpp_int> tail;
};

void enumerate_dfs(
    const vector<ll>& R,
    const vector<ll>& N,
    vector<int>& revA,
    vector<int>& revC,
    vector<Candidate>& out
) {
    int m = (int)R.size();

    bool zero = true;
    for (ll x : R) {
        if (x != 0) {
            zero = false;
            break;
        }
    }

    if (zero) {
        Candidate cand;
        cand.a.assign(revA.rbegin(), revA.rend());
        cand.c.assign(revC.rbegin(), revC.rend());
        out.push_back(move(cand));
        return;
    }

    if (R[0] <= 0) return;

    for (ll x = 1; x <= R[0]; x++) {
        ll maxc = R[0] / x;

        for (int i = 1; i < m; i++) {
            maxc = min(maxc, R[i] / N[i - 1]);
            if (maxc == 0) break;
        }

        for (ll c = 1; c <= maxc; c++) {
            vector<ll> nR(m);
            nR[0] = R[0] - c * x;
            for (int i = 1; i < m; i++) {
                nR[i] = R[i] - c * N[i - 1];
            }

            vector<ll> nN;
            if (m > 1) {
                nN.resize(m - 1);
                nN[0] = x;
                for (int i = 1; i < m - 1; i++) {
                    nN[i] = N[i - 1];
                }
            }

            revA.push_back((int)x);
            revC.push_back((int)c);

            enumerate_dfs(nR, nN, revA, revC, out);

            revA.pop_back();
            revC.pop_back();
        }
    }
}

vector<cpp_int> generate_tail(const vector<int>& c, const vector<int>& a, int need) {
    int k = (int)c.size();

    vector<cpp_int> seq;
    seq.reserve(k + need);

    for (int x : a) seq.push_back(x);

    vector<cpp_int> tail;
    tail.reserve(need);

    for (int t = 0; t < need; t++) {
        cpp_int nxt = 0;
        int start = (int)seq.size() - k;

        for (int j = 0; j < k; j++) {
            nxt += cpp_int(c[j]) * seq[start + j];
        }

        seq.push_back(nxt);
        tail.push_back(nxt);
    }

    return tail;
}

bool cand_cmp(const Candidate& x, const Candidate& y) {
    if (lexicographical_compare(
            x.tail.begin(), x.tail.end(),
            y.tail.begin(), y.tail.end()
        )) return true;

    if (lexicographical_compare(
            y.tail.begin(), y.tail.end(),
            x.tail.begin(), x.tail.end()
        )) return false;

    return lexicographical_compare(
        x.c.begin(), x.c.end(),
        y.c.begin(), y.c.end()
    );
}

/* ---------------- 系数序列兜底反排名 ---------------- */

bool check_coeff(
    const vector<int>& c,
    const vector<cpp_int>& B,
    vector<int>& a
) {
    int k = (int)c.size();
    int m = (int)B.size();

    if (k > m) return false;

    a.assign(k, 0);

    // 用前 k 个生成项从后往前解初值
    for (int i = k - 1; i >= 0; i--) {
        cpp_int rhs = B[i];

        for (int j = 1; j < k; j++) {
            int pos = i + j;
            cpp_int term;

            if (pos < k) term = a[pos];
            else term = B[pos - k];

            rhs -= cpp_int(c[j]) * term;
        }

        if (rhs <= 0) return false;
        if (rhs % c[0] != 0) return false;

        cpp_int val = rhs / c[0];
        if (val <= 0 || val > 1000000) return false;

        a[i] = val.convert_to<int>();
    }

    // 验证整个前缀
    for (int t = 0; t < m; t++) {
        cpp_int sum = 0;

        for (int j = 0; j < k; j++) {
            int pos = t + j;
            cpp_int term;

            if (pos < k) term = a[pos];
            else term = B[pos - k];

            sum += cpp_int(c[j]) * term;
        }

        if (sum != B[t]) return false;
    }

    return true;
}

bool coeff_dfs(
    int rem,
    vector<int>& cur,
    const vector<cpp_int>& B,
    ll& rank,
    vector<int>& ansC,
    vector<int>& ansA
) {
    if (!cur.empty()) {
        vector<int> a;
        if (check_coeff(cur, B, a)) {
            rank--;
            if (rank == 0) {
                ansC = cur;
                ansA = a;
                return true;
            }
        }
    }

    if (rem == 0) return false;

    for (int x = 1; x <= rem; x++) {
        cur.push_back(x);

        if (coeff_dfs(rem - x, cur, B, rank, ansC, ansA)) {
            return true;
        }

        cur.pop_back();
    }

    return false;
}

void print_int_vec(const vector<int>& v) {
    for (int i = 0; i < (int)v.size(); i++) {
        if (i) cout << ' ';
        cout << v[i];
    }
    cout << '\n';
}

void print_cpp_vec_10(const vector<cpp_int>& v) {
    for (int i = 0; i < 10; i++) {
        if (i) cout << ' ';
        cout << v[i];
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    /*
       先统计第一个生成项等于 x 的递推式数量。

       b1 = sum c_i * a_i。
       令 p_i = c_i * a_i。
       p_i 是正整数，sum p_i = b1。
       每个 p_i 有 d(p_i) 种拆成 c_i * a_i 的方式。
    */
    const int MAXV = 100;

    vector<ll> divisor_cnt(MAXV + 1, 0);
    for (int i = 1; i <= MAXV; i++) {
        for (int j = i; j <= MAXV; j += i) {
            divisor_cnt[j]++;
        }
    }

    vector<ll> f(MAXV + 1, 0);
    f[0] = 1;

    for (int s = 1; s <= MAXV; s++) {
        for (int p = 1; p <= s; p++) {
            f[s] = cap_mul_add(f[s], divisor_cnt[p], f[s - p]);
        }
    }

    int first = 1;
    ll rank = n;

    while (true) {
        if (rank > f[first]) {
            rank -= f[first];
            first++;
        } else {
            break;
        }
    }

    vector<ll> prefixLL;
    vector<cpp_int> prefixBig;

    prefixLL.push_back(first);
    prefixBig.push_back(first);

    ll curCnt = f[first];

    int targetLen = max(10, 2 * first);

    /*
       不断确定下一个生成项。
       如果当前前缀下候选数量已经很少，就直接枚举。
    */
    while (curCnt > ENUM_LIMIT && (int)prefixLL.size() < 2 * first) {
        DistSolver solver(prefixLL);
        const auto& dist = solver.solve();

        bool found = false;

        for (auto [val, cnt] : dist) {
            if (rank > cnt) {
                rank -= cnt;
            } else {
                prefixLL.push_back(val);
                prefixBig.push_back(val);
                curCnt = cnt;
                found = true;
                break;
            }
        }

        if (!found) return 0;
    }

    vector<int> ansC, ansA;
    vector<cpp_int> ansTail;

    if (curCnt <= ENUM_LIMIT) {
        vector<ll> R = prefixLL;
        vector<ll> N;

        if ((int)prefixLL.size() >= 2) {
            for (int i = 0; i + 1 < (int)prefixLL.size(); i++) {
                N.push_back(prefixLL[i]);
            }
        }

        vector<Candidate> candidates;
        vector<int> revA, revC;

        enumerate_dfs(R, N, revA, revC, candidates);

        for (auto& cand : candidates) {
            cand.tail = generate_tail(cand.c, cand.a, targetLen);
        }

        sort(candidates.begin(), candidates.end(), cand_cmp);

        Candidate chosen = candidates[rank - 1];

        ansC = chosen.c;
        ansA = chosen.a;
        ansTail = generate_tail(ansC, ansA, 10);
    } else {
        /*
           理论兜底：
           如果已经确定了 2 * first 个生成项，
           那么生成部分已经唯一确定。
           剩下只需要按照系数序列字典序反排名。
        */
        vector<int> cur;
        coeff_dfs(first, cur, prefixBig, rank, ansC, ansA);
        ansTail = generate_tail(ansC, ansA, 10);
    }

    cout << ansC.size() << '\n';
    print_int_vec(ansC);
    print_int_vec(ansA);
    print_cpp_vec_10(ansTail);

    return 0;
}