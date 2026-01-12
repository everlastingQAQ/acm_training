#include<bits/stdc++.h> 
#define int long long 
using ll = long long; 

using namespace std; 
typedef pair<int,int> PII; 
typedef pair<int,PII> PIII; 
const int mod = 998244353; 
const double eps = 1e-10; 
void solve() { 
    int n, a, b; 
    cin >> n >> a >> b; 
    int gb = lcm (a, b); 
    while (n --) { 
        ll x = 0, y = 0, t; 
        cin >> t; 
        if (a == b) { 
            x = 0, y = (t + a - 1) / a; 
            cout << x << ' ' << y << endl; 
        }else { 
            y = t / gb * (gb / a); 
            int res = t - y * b; 
            if (res == 0) { 
                cout << x << ' ' << y << endl; 
                return; 
            } 
            int mx = (res + a - 1) / a; 
            int pr, mnp = LLONG_MAX, mni; 
            for (int i = 0; i <= mx; i ++) { 
                pr = i * a + (res - i * a + b - 1) / b * b; 
                if (pr < mnp) { 
                    mnp = pr; mni = i; 
                } 
            } 
            x += mni; 
            y += (res - mni * a + b - 1) / b; 
            cout << x << ' ' << y << endl; 
        } 
    } 
} 

signed main(){ 
    ios::sync_with_stdio(false); int _=1; while(_--){ solve(); } return 0; }