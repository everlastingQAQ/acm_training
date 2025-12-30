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
    cout << 10000 << '\n';
    for (int j = 1; j <= 10000; j++) {
        cout << 20 << '\n';
        ll cnt = rand();
        for (int i = 1; i <= 20; i++) {
            if (cnt % 2 == 0) cout << 2;
            else if (cnt % 5 == 0) cout << 5;
            else if (cnt % 6 == 0) cout << 6;
            else cout << 0;
            cnt = rand();
        }
        cout << '\n';
    }
    
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        solve();
    }
    return 0;
}