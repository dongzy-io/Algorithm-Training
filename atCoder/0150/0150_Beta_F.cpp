#include<bits/stdc++.h>
using namespace std;

class DSU{
    private:
        vector<int> fa;
        vector<int> cnt;
    public:
        DSU(int n){
            fa.resize(n+1);
            for(int i=1;i<=n;i++){
                fa[i]=i;
            }
            cnt.assign(n+1,1);
        } 

        int find(int id){
            if(fa[id]==id)  
                return id;
            return fa[id]=find(fa[id]);
        }

        bool unite(int a,int b){
            int ancestor_a=find(a);
            int ancestor_b=find(b);
            if(ancestor_a==ancestor_b)
                return true;
            fa[ancestor_a]=ancestor_b;
            cnt[ancestor_b]+=cnt[ancestor_a];
            return false;
        }

        void output(int id){
            cout<<cnt[find(id)];
        }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    DSU dsu(n);
    while(q--){
        int opt;
        cin>>opt;
        if(opt==1){
            int a,b;
            cin>>a>>b;
            dsu.unite(a,b);            
        }else{
            int x;
            cin>>x;
            dsu.output(x);
            cout<<'\n';
        }
    }
    return 0;
}