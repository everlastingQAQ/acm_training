#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class SEG{
    public:
        int n;
        vector<int> len0,len1;
        vector<int> tag;

        SEG(int n):n(n){
            len0.assign(n<<2,0);
            len1.assign(n<<2,0);
            tag.assign(n<<2,0);
        }

        void up(int i){
            len0[i] = len0[i<<1]+len0[i<<1|1];
            len1[i] = len1[i<<1]+len1[i<<1|1];
        }

        void lazy(int i){
            swap(len0[i],len1[i]);
            tag[i] ^= 1;
        }

        void down(int i){
            if(tag[i]){
                lazy(i<<1);
                lazy(i<<1|1);
                tag[i] = 0;
            }
        }

        void build(int l,int r,int i,string& a){
            if(l==r){
                len0[i] = (a[l]=='0');
                len1[i] = (a[l]=='1');
            }
            else{
                int mid = (l+r)>>1;
                build(l,mid,i<<1,a);
                build(mid+1,r,i<<1|1,a);
                up(i);
            }
            tag[i] = 0;
        }

        void upd(int u,int v,int l,int r,int i){
            if(u<=l && r<=v){
                return lazy(i);
            }
            int mid = l+r>>1;
            down(i);
            if(u<=mid) upd(u,v,l,mid,i<<1);
            if(v>mid) upd(u,v,mid+1,r,i<<1|1);
            up(i);
        }

        void upd(int l,int r){
            upd(l,r,1,n,1);
        }

        int query(int u,int v,int l,int r,int i){
            if(u<=l && r<=v){
                return len1[i];
            }
            int mid = (l+r)>>1;
            down(i);
            int res = 0;
            if(u<=mid) res += query(u,v,l,mid,i<<1);
            if(v>mid) res += query(u,v,mid+1,r,i<<1|1);
            return res;
        }

        int query(int l,int r){
            return query(l,r,1,n,1);
        }
};

void solve(){
    int n,q; cin >> n >> q;
    string s; cin >> s;
    s = ' ' + s;

    SEG seg(n);
    seg.build(1,n,1,s);
    while(q--){
        int op; cin >> op;
        int l,r; cin >> l >> r;
        if(op==1){
            seg.upd(l,r);
        }
        else{
            cout << seg.query(l,r) << endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _ = 1;
    // cin >> _;
    while(_--){
        solve();
    }

    return 0;
}
