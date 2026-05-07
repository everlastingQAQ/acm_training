#include <bits/stdc++.h>

using u32 = unsigned int;
using u64 = unsigned long long;

using i64 = long long;
using i128 = __int128_t;

namespace ranges = std::ranges;

template<class T>
constexpr T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
 
template<int P>
struct MInt {
    int x;
    constexpr MInt() : x{} {}
    constexpr MInt(i64 x) : x{norm(x % getMod())} {}
    
    static int Mod;

    constexpr static int getMod() {
        if (P > 0) {
            return P;
        } else {
            return Mod;
        }
    }

    constexpr static void setMod(int Mod_) {
        Mod = Mod_;
    }

    constexpr int norm(int x) const {
        if (x < 0) {
            x += getMod();
        }
        if (x >= getMod()) {
            x -= getMod();
        }
        return x;
    }

    constexpr int val() const {
        return x;
    }

    explicit constexpr operator int() const {
        return x;
    }

    constexpr MInt operator - () const {
        MInt res;
        res.x = norm(getMod() - x);
        return res;
    }

    constexpr MInt inv() const {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }

    constexpr MInt &operator *= (MInt rhs) & {
        x = 1LL * x * rhs.x % getMod();
        return *this;
    }

    constexpr MInt &operator += (MInt rhs) & {
        x = norm(x + rhs.x);
        return *this;
    }

    constexpr MInt &operator -= (MInt rhs) & {
        x = norm(x - rhs.x);
        return *this;
    }

    constexpr MInt &operator /= (MInt rhs) & {
        return *this *= rhs.inv();
    }

    friend constexpr MInt operator * (MInt lhs, MInt rhs) {
        MInt res = lhs;
        res *= rhs;
        return res;
    }

    friend constexpr MInt operator + (MInt lhs, MInt rhs) {
        MInt res = lhs;
        res += rhs;
        return res;
    }

    friend constexpr MInt operator - (MInt lhs, MInt rhs) {
        MInt res = lhs;
        res -= rhs;
        return res;
    }

    friend constexpr MInt operator / (MInt lhs, MInt rhs) {
        MInt res = lhs;
        res /= rhs;
        return res;
    }

    friend constexpr std::istream &operator >> (std::istream &is, MInt &a) {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }

    friend constexpr std::ostream &operator << (std::ostream &os, const MInt &a) {
        return os << a.val();
    }

    friend constexpr bool operator == (MInt lhs, MInt rhs) {
        return lhs.val() == rhs.val();
    }

    friend constexpr bool operator != (MInt lhs, MInt rhs) {
        return lhs.val() != rhs.val();
    }
};
 
template<>
int MInt<0>::Mod = 1;
 
template<int V, int P>
constexpr MInt<P> CInv = MInt<P>(V).inv();
 
constexpr int P = 998244353;
using Z = MInt<P>;

struct Comb {
    int n;
    std::vector<Z> _fac;
    std::vector<Z> _invfac;
    std::vector<Z> _inv;
    
    Comb() : n{0}, _fac{1}, _invfac{1}, _inv{0} {}
    Comb(int n) : Comb() {
        init(n);
    }
    
    void init(int m) {
        m = std::min(m, Z::getMod() - 1);
        if (m <= n) return;
        _fac.resize(m + 1);
        _invfac.resize(m + 1);
        _inv.resize(m + 1);
        
        for (int i = n + 1; i <= m; i++) {
            _fac[i] = _fac[i - 1] * i;
        }
        _invfac[m] = _fac[m].inv();
        for (int i = m; i > n; i--) {
            _invfac[i - 1] = _invfac[i] * i;
            _inv[i] = _invfac[i] * _fac[i - 1];
        }
        n = m;
    }
    
    Z fac(int m) {
        if (m > n) init(2 * m);
        return _fac[m];
    }
    
    Z invfac(int m) {
        if (m > n) init(2 * m);
        return _invfac[m];
    }

    Z inv(int m) {
        if (m > n) init(2 * m);
        return _inv[m];
    }

    Z binom(int n, int m) {
        if (n < m || m < 0) return 0;
        return fac(n) * invfac(m) * invfac(n - m);
    }
} comb;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    std::vector<std::vector<int>> edge(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        edge[u].emplace_back(v);
        edge[v].emplace_back(u);
    }
    for (int i = 1; i <= n; i++) {
        std::sort(edge[i].begin(), edge[i].end(), [&] (auto &x, auto &y) {
            return a[x] < a[y];
        });
    }
    std::vector<int> tmp, f(n + 1);
    tmp.reserve(n);
    auto dfs = [&] (auto &&self, int p, int fa) -> void {
        tmp.emplace_back(a[p]);
        f[p] = fa;
        for (auto c : edge[p]) {
            if (c != fa) {
                self(self, c, p);
            }
        }
    };
 
    dfs(dfs, 1, 0);
     
    for (int i = 1; i < n; i++) {
        if (tmp[i] < tmp[i - 1]) {
            std::cout << 0 << "\n";
            return ;
        }
    }
    Z ans = 1;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        std::map<int, int> mp;
        for (auto c : edge[i]) {
            if (c != f[i]) {
                mp[a[c]]++;
                cnt++;
            }
        }
        for (auto [u, v] : mp) {
            ans *= comb.fac(v);
        }
        ans /= comb.fac(cnt);
    }
    std::cout << ans << "\n";
    return ;
}

int main() {
    std::cin.tie(nullptr) -> std::ios_base::sync_with_stdio(false);

    int t = 1;
    std::cin >> t;

    while (t-->0) {
        solve();
    }

    return 0;
}