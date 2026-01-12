#include<bits/stdc++.h>  
#define int long long 
using ll = long long; 

using namespace std; 
typedef pair<int,int> PII; 
typedef pair<int,PII> PIII; 
const int mod = 998244353; 
const double eps = 1e-10; 

const int N = 1e5 + 10;
int primes[N];
bool vis[N];
int mnt[N];
int cnt = 1;
vector<vector<PII>> mnf(N);

void get_primes(int n) {
    mnt[1] = 1;
    for (int i = 2; i <= n; i ++) {
        if (!vis[i]) {
            primes[cnt ++] = i;
            mnt[i]  = i;
        }   

        for (int j = 1; j < cnt && 1ll * i * primes[j] <= n; j ++) {
            mnt[i * primes[j]] = primes[j];
            vis[i * primes[j]] = 1;
            if (i % primes[j] == 0) break;
        }
    }

    mnf[1].push_back({1, 1});
    for (int i = 2; i <= n; i ++) {
        int t = i;
        while (t != 1) {
            int cn = 0;
            int mf = mnt[t];
            while (t % mf == 0) {
                cn ++;
                t /= mf;
            }
            mnf[i].push_back({mf, cn});
        }
    }
}

void solve() { 
    int n;
    cin >> n;
    get_primes(n);
    for (int i = 2; i <= n; i ++) {
        cout << i << ": ";
        for (auto [a, b] : mnf[i])  {
            cout << a << ' ' << b << " or ";
        }
        cout << endl;
    }
    
} 

signed main(){ 
    ios::sync_with_stdio(false); int _=1; while(_--){ solve(); } return 0; }