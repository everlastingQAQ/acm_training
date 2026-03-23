#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void read(int &x){ 
	int f=1;x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	x*=f;
}

void solve ()
{
    int n;
    read(n);
    vector <int> cnt((int)1e5 + 1, 0);

    for (int i = 1; i <= n; i++) {
        int t;
        read(t);
        cnt[t]++;
    }

    queue <i64> q1, q2;
    for (int i = 1; i <= (int)1e5; i++) {
        for (int j = 1; j <= cnt[i]; j++) {
            q1.push(i);
        }
    }

    i64 ans = 0;

    for (int i = 1; i < n; i++) {
        i64 x, y;   
        if ((!q1.empty() && !q2.empty() && q1.front() < q2.front()) || q2.empty()) {
            x = q1.front();
            q1.pop();
        }else {
            x = q2.front();
            q2.pop();
        }
        if ((!q1.empty() && !q2.empty() && q1.front() < q2.front()) || q2.empty()) {
            y = q1.front();
            q1.pop();
        }else {
            y = q2.front();
            q2.pop();
        }

        ans += x + y;
        q2.push(x + y);
    }

    printf("%lld", ans);
}   
    
int main ()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 