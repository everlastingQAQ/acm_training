#include <bits/stdc++.h>
using namespace std;
#define int long long

char *p1,*p2,buf[100000];
#define nc() (p1==p2 && (p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
int read()
{
    int x=0,f=1;
    char ch=nc();
    while(ch<48||ch>57)
    {
        if(ch=='-')
            f=-1;
        ch=nc();
    }
    while(ch>=48&&ch<=57)
        x=x*10+ch-48,ch=nc();
   	return x*f;
}

vector <int> c((int)2e5 + 10);

void solve ()
{
    int n, k;
    n = read();
    k = read();
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        v[i] = read();
    }
    int l = 0, r = ranges::max(v | views::drop(1)) + 1;

    auto check = [&] (int md) -> bool {
        int cnt = 0;
        int mex = 0;
        
        for (int i = 1; i <= n; i++) {
            if (v[i] <= (int)2e5 + 3) c[v[i]] = true;
            while (c[mex]) {
                mex++;
            }
            if (mex >= md) {
                for (int i = 0; i <= mex; i++) {
                    c[i] = 0;
                }
                mex = 0;
                cnt++;
            }
        }
        for (int i = 0; i <= c.size() + 1; i++) {
            c[i] = 0;
        }
        return cnt >= k;
    };

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) l = mid + 1;
        else r = mid - 1;
    }
    printf("%lld\n", r);
} 
    
int32_t main ()
{
    int _ = 1;
    _ = read();
    while (_--) {
        solve();
    }
    return 0;
} 