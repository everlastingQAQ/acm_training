#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 1;
const double eps = 1e-5;
vector <bool> isPrime(MAXN + 1, true);
vector <int> Primes;
vector <vector<int>> pfac(MAXN + 1);
int cnt[MAXN];

void find_primes ()
{
    for (int i = 2; i < MAXN; i++) {
        if (isPrime[i]) {
            Primes.push_back(i);
        }
        for (int j = 0; j < Primes.size() && i * Primes[j] <= MAXN; j++) {
            isPrime[i * Primes[j]] = false;
            if (i % Primes[j] == 0) break;
        }
    }
}

void find_fac ()
{
    for (int i = 2; i <= MAXN; i++) {
        if (!pfac[i].empty()) {
            continue;
        }
        for (int j = i; j <= MAXN; j += i) {
            pfac[j].push_back(i);
        }
    }
}

void solve ()
{
    int n;
    cin >> n;

    int a[MAXN];
    int b[MAXN];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int ans = 2;
    
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
        for (int x : pfac[a[i]]) {
            if (cnt[x] > 0) {
                ans = 0;
            }
            cnt[x]++;
        }
    }

    if (ans == 0) {
        cout << 0 << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int x : pfac[a[i]]) {
            cnt[x]--;
        }
        for (int x : pfac[a[i] + 1]) {
            if (cnt[x] > 0) {
                ans = min(ans, 1);
            }
        }
        for (int x : pfac[a[i]]) {
            cnt[x]++;
        }
    }

    cout << ans << endl;
}

int main ()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	int _ = 1;
	cin >> _;

    find_fac();

    while (_--) {
        solve();
    }

    return 0;
}