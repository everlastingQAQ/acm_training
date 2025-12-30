#include<bits/stdc++.h>
#define pi acos(-1)
#define fi first 
#define se second 
#define int long long
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll & i : a) cin >> i;
    ranges::sort(a);

    if (m > n + 1) {
        cout << "NO" << endl;
    } else {
        int cur = 0, mx = 1, ok = 1;
        for (int i = 1; i < n; i ++) {
            if (a[i] - a[i - 1] == 1) {
                cur ++;
            } else if(a[i] - a[i - 1] == 2 && ok) {
                cur += 2;
                ok = 0;
            } else if(ok) {
                cur ++;
                mx = max(mx, cur);
                cur = 0;
                // cout << mx << ' ';
            } else {
                mx = max(mx, cur);
                cur = 0;
                ok = 1;
                // cout << mx << endl;
            }
        }
        if (cur != 0) {
            if(ok) mx = max(cur +1 , mx);
            else mx = max(mx, cur);
        }
        if (mx >= m - 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    int _=1;
    cin>>_;

    while(_--){
        solve();
    }
    return 0;
}