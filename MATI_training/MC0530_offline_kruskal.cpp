#include<bits/stdc++.h>
using namespace std;

class DSU
{
    private:
        vector<int> fa;
        vector<int> sz;
    public:
        DSU(int n){
            fa.resize(n);
            sz.resize(n);
            for(int i=0;i<n;i++){
                fa[i]=i;
                sz[i]=1;
            }
        }

        int find(int id){
            if(fa[id]==id)
                return id;
            return fa[id]=find(fa[id]);
        }

        void unite(int x, int y){
            x=find(x);
            y=find(y);
            if(x==y)
                return ;
            if(sz[x]<sz[y])
                swap(x,y);
            fa[y]=x;
            sz[x]+=sz[y];
        }

        int getSize(int id){
            return sz[find(id)];
        }
}; 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int> thresholds(n);
    vector<array<int,3>> edges(m);//threshold u v
    for(auto &x: thresholds){
        cin>>x;
    }
    for(auto &e: edges){    
        int u,v;
        cin>>u>>v;
        e[0]=max(thresholds[--u],thresholds[--v]);
        e[1]=u;
        e[2]=v;
    }
    sort(edges.begin(),edges.end());
    int q;
    cin>>q;
    vector<array<int,3>> queries(q);//wealth start id
    for(int i=0;i<q;i++){
        cin>>queries[i][1];
        queries[i][1]--;
        cin>>queries[i][0];
        queries[i][2]=i;
    }
    sort(queries.begin(),queries.end());
    vector<int> ans(q);
    int cnt=0;
    DSU dsu(n);
    for(int i=0;i<q;i++){
        while(cnt<m&&edges[cnt][0]<=queries[i][0]){
            dsu.unite(edges[cnt][2],edges[cnt][1]);
            cnt++;
        }
        ans[queries[i][2]]=dsu.getSize(queries[i][1]);
    }
    for(int i=0;i<q;i++){ 
        cout<<ans[i]<<'\n';
    }
    return 0;
}