#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 1e6 + 1;

bool vis[N];
int primes[N], mnp[N];
int cnt = 0;
vector <vector<int> > v(N);

void get_factors ()
{
    mnp[1] = 1;
    for (int i = 2; i < N; i++) {
        if (!vis[i]) {
            primes[++cnt] = i;//1-based
            mnp[i] = i;
        }
        for (int j = 1; j <= cnt && i * primes[j] < N; j++) {
            vis[i * primes[j]] = 1;
            mnp[i * primes[j]] = primes[j];
            if (i % primes[j] == 0) break;  
        }
    }

    v[1].push_back(1);
    for (int i = 1; i < N; i++) {
        int t = i;
        while (t > 1) {
            int p = mnp[t];
            while (t % p == 0) {
                t /= p;
                v[i].push_back(p);
            }
        }
    }
}

void solve ()
{
    i64 a, b, c;
    cin >> a >> b >> c;
    if (a > 0 && b > 0 && c > 0) {
        i64 mx1 = (1LL << v[a].size()) - 1;
        i64 mx2 = (1LL << v[c].size()) - 1;
        set <array <i64, 2> > st1;
        set <array <i64, 2> > st2;

        for (int mask1 = 1; mask1 <= mx1; mask1++) {
            i64 a1 = 1, a2 = 1;
            for (int i = 0; i < v[a].size(); i++) {
                if (mask1 >> i & 1) a1 *= v[a][i];
                else a2 *= v[a][i];
            }
            st1.insert({a1, a2});
        }

        for (int mask2 = 1; mask2 <= mx2; mask2++) {
            i64 b1 = 1, b2 = 1;
            for (int i = 0; i < v[c].size(); i++) {
                if (mask2 >> i & 1) b1 *= v[c][i];
                else b2 *= v[c][i];
            }
            st2.insert({b1, b2});
        }

        for (auto [a1, a2] : st1) {
            for (auto [b1, b2] : st2) {
                if (a1 * b2 + a2 * b1 == b) {
                    cout << a1 << ' ' << b1 << ' ' << a2 << ' ' << b2 << '\n';
                    return;
                }
                if (a1 * b1 + a2 * b2 == b) {
                    cout << a1 << ' ' << b2 << ' ' << a2 << ' ' << b1 << '\n';
                    return;
                }
            }
        }

        cout << "NO\n";

    }else if (a > 0 && b < 0 && c > 0) {
        b = -b;
        i64 mx1 = (1LL << v[a].size()) - 1;
        i64 mx2 = (1LL << v[c].size()) - 1;
        set <array <i64, 2> > st1;
        set <array <i64, 2> > st2;

        for (int mask1 = 1; mask1 <= mx1; mask1++) {
            i64 a1 = 1, a2 = 1;
            for (int i = 0; i < v[a].size(); i++) {
                if (mask1 >> i & 1) a1 *= v[a][i];
                else a2 *= v[a][i];
            }
            if (a1 > a2) swap(a1, a2);
            st1.insert({a1, a2});
        }

        for (int mask2 = 1; mask2 <= mx2; mask2++) {
            i64 b1 = 1, b2 = 1;
            for (int i = 0; i < v[c].size(); i++) {
                if (mask2 >> i & 1) b1 *= v[c][i];
                else b2 *= v[c][i];
            }
            if (b1 > b2) swap(b1, b2);
            st2.insert({b1, b2});
        }

        for (auto [a1, a2] : st1) {
            for (auto [b1, b2] : st2) {
                if (a1 * b2 + a2 * b1 == b) {
                    cout << a1 << ' ' << -b1 << ' ' << a2 << ' ' << -b2 << '\n';
                    return;
                }
                if (a1 * b1 + a2 * b2 == b) {
                    cout << a1 << ' ' << -b2 << ' ' << a2 << ' ' << -b1 << '\n';
                    return;
                }
            }
        }

        cout << "NO\n";
    }else if ((a > 0 && b > 0 && c < 0) || (a > 0 && b < 0 && c < 0)) {
        bool ok = false;
        if (c < 0) ok = true;
        c = -c;
        i64 mx1 = (1LL << v[a].size()) - 1;
        i64 mx2 = (1LL << v[c].size()) - 1;
        set <array <i64, 2> > st1;
        set <array <i64, 2> > st2;

        for (int mask1 = 1; mask1 <= mx1; mask1++) {
            i64 a1 = 1, a2 = 1;
            for (int i = 0; i < v[a].size(); i++) {
                if (mask1 >> i & 1) a1 *= v[a][i];
                else a2 *= v[a][i];
            }
            if (a1 > a2) swap(a1, a2);
            st1.insert({a1, a2});
        }

        for (int mask2 = 1; mask2 <= mx2; mask2++) {
            i64 b1 = 1, b2 = 1;
            for (int i = 0; i < v[c].size(); i++) {
                if (mask2 >> i & 1) b1 *= v[c][i];
                else b2 *= v[c][i];
            }
            if (b1 > b2) swap(b1, b2);
            st2.insert({b1, b2});
        }

        for (auto [a1, a2] : st1) {
            for (auto [b1, b2] : st2) {
                if (a1 * b2 - a2 * b1 == b) {
                    cout << a1 << ' ' << -b1 << ' ' << a2 << ' ' << b2 << '\n';
                    return;
                }
                if (-a1 * b1 + a2 * b2 == b) {
                    cout << a1 << ' ' << b2 << ' ' << a2 << ' ' << -b1 << '\n';
                    return;
                }
                if (-a1 * b2 + a2 * b1 == b) {
                    cout << a1 << ' ' << b1 << ' ' << a2 << ' ' << -b2 << '\n';
                    return;
                }
                if (a1 * b1 - a2 * b2 == b) {
                    cout << a1 << ' ' << -b2 << ' ' << a2 << ' ' << b1 << '\n';
                    return;
                }
            }
        }

        cout << "NO\n";
    }else if ((a < 0 && b > 0 && c > 0) || (a < 0 && b < 0 && c > 0)) {
        bool ok = false;
        if (a < 0) ok = true;
        a = -a;
        i64 mx1 = (1LL << v[a].size()) - 1;
        i64 mx2 = (1LL << v[c].size()) - 1;
        set <array <i64, 2> > st1;
        set <array <i64, 2> > st2;

        for (int mask1 = 1; mask1 <= mx1; mask1++) {
            i64 a1 = 1, a2 = 1;
            for (int i = 0; i < v[a].size(); i++) {
                if (mask1 >> i & 1) a1 *= v[a][i];
                else a2 *= v[a][i];
            }
            if (a1 > a2) swap(a1, a2);
            st1.insert({a1, a2});
        }

        for (int mask2 = 1; mask2 <= mx2; mask2++) {
            i64 b1 = 1, b2 = 1;
            for (int i = 0; i < v[c].size(); i++) {
                if (mask2 >> i & 1) b1 *= v[c][i];
                else b2 *= v[c][i];
            }
            if (b1 > b2) swap(b1, b2);
            st2.insert({b1, b2});
        }

        for (auto [a1, a2] : st1) {
            for (auto [b1, b2] : st2) {
                if (a1 * b2 - a2 * b1 == b) {
                    cout << a1 << ' ' << b1 << ' ' << -a2 << ' ' << b2 << '\n';
                    return;
                }
                if (-a1 * b1 + a2 * b2 == b) {
                    cout << -a1 << ' ' << b2 << ' ' << a2 << ' ' << b1 << '\n';
                    return;
                }
                if (-a1 * b2 + a2 * b1 == b) {
                    cout << -a1 << ' ' << b1 << ' ' << a2 << ' ' << b2 << '\n';
                    return;
                }
                if (a1 * b1 - a2 * b2 == b) {
                    cout << a1 << ' ' << b2 << ' ' << -a2 << ' ' << b1 << '\n';
                    return;
                }
            }
        }
        cout << "NO\n";
    }else if (a < 0 && b > 0 && c < 0) {
        a = -a;
        c = -c;
        b = -b;
        i64 mx1 = (1LL << v[a].size()) - 1;
        i64 mx2 = (1LL << v[c].size()) - 1;
        set <array <i64, 2> > st1;
        set <array <i64, 2> > st2;

        for (int mask1 = 1; mask1 <= mx1; mask1++) {
            i64 a1 = 1, a2 = 1;
            for (int i = 0; i < v[a].size(); i++) {
                if (mask1 >> i & 1) a1 *= v[a][i];
                else a2 *= v[a][i];
            }
            if (a1 > a2) swap(a1, a2);
            st1.insert({a1, a2});
        }

        for (int mask2 = 1; mask2 <= mx2; mask2++) {
            i64 b1 = 1, b2 = 1;
            for (int i = 0; i < v[c].size(); i++) {
                if (mask2 >> i & 1) b1 *= v[c][i];
                else b2 *= v[c][i];
            }
            if (b1 > b2) swap(b1, b2);
            st2.insert({b1, b2});
        }

        for (auto [a1, a2] : st1) {
            for (auto [b1, b2] : st2) {
                if (-a1 * b2 - a2 * b1 == b) {
                    cout << -a1 << ' ' << b1 << ' ' << a2 << ' ' << -b2 << '\n';
                    return;
                }
                if (-a1 * b1 - a2 * b2 == b) {
                    cout << -a1 << ' ' << b2 << ' ' << a2 << ' ' << -b1 << '\n';
                    return;
                }
            }
        }
        cout << "NO\n";
    }else if (a < 0 && b < 0 && c < 0) {
        a = -a;
        b = -b;
        c = -c;
        i64 mx1 = (1LL << v[a].size()) - 1;
        i64 mx2 = (1LL << v[c].size()) - 1;
        set <array <i64, 2> > st1;
        set <array <i64, 2> > st2;

        for (int mask1 = 1; mask1 <= mx1; mask1++) {
            i64 a1 = 1, a2 = 1;
            for (int i = 0; i < v[a].size(); i++) {
                if (mask1 >> i & 1) a1 *= v[a][i];
                else a2 *= v[a][i];
            }
            if (a1 > a2) swap(a1, a2);
            st1.insert({a1, a2});
        }

        for (int mask2 = 1; mask2 <= mx2; mask2++) {
            i64 b1 = 1, b2 = 1;
            for (int i = 0; i < v[c].size(); i++) {
                if (mask2 >> i & 1) b1 *= v[c][i];
                else b2 *= v[c][i];
            }
            if (b1 > b2) swap(b1, b2);
            st2.insert({b1, b2});
        }

        for (auto [a1, a2] : st1) {
            for (auto [b1, b2] : st2) {
                if (a1 * b2 + a2 * b1 == b) {
                    cout << -a1 << ' ' << -b1 << ' ' << a2 << ' ' << b2 << '\n';
                    return;
                }
                if (a1 * b1 + a2 * b2 == b) {
                    cout << -a1 << ' ' << -b2 << ' ' << a2 << ' ' << b1 << '\n';
                    return;
                }
            }
        }

        cout << "NO\n";
    }else if (c == 0) {
        cout << 1 << ' ' << 0 << ' ' << a << ' ' << b << '\n';
    }
    
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    get_factors();
    while (_--) {
        solve();
    }
    return 0;
}