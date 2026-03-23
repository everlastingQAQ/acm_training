#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;

int t,n,a[N],b[N],vis[N];

int read(){
    int x=0,f=1;char c=getchar();
    while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
    while (c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
    return x*f;
}

int main(){
    t=read();
    while (t--){
        n=read();
        for (int i=1;i<=n;i++)
            a[i]=read();
        for (int i=1;i<=n;i++)
            b[i]=read();
        memset(vis,0,sizeof vis);
        if (a[n]==b[n]){
            cout <<n<<endl;
            continue;
        }
        int ans=0;
        for (int i=n-1;i>=1;i--){
            if (a[i]==b[i]||a[i]==a[i+1]||b[i]==b[i+1]||vis[a[i]]==1||vis[b[i]]==1){
                ans=i;
                break;
            }
            vis[a[i+1]]=1;
            vis[b[i+1]]=1;
        }
        cout <<ans<<endl;
    }
    return 0;
}
