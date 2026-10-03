#include<bits/stdc++.h>
using namespace std;

class DSU
{
    private:
        vector<int> fa;
        vector<int> sz;
    public:
        DSU(int n): fa(n+1),sz(n+1,1){
            iota(fa.begin(),fa.end(),0);
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
            if(sz[ancestor_a]<sz[ancestor_b])
                swap(ancestor_a,ancestor_b);
            fa[ancestor_b]=ancestor_a;
            sz[ancestor_a]+=sz[ancestor_b];
            return false;
        }

        int cnt(int id){
            return sz[find(id)];
        }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,q;
    cin>>n>>k>>q;
    vector<int> a(k);
    vector<int> b(k);
    for(int i=0;i<k;i++){
        cin>>a[i]>>b[i];
    }
    while(q--){
        int opt,id,curr;
        cin>>opt>>id>>curr;
        if(opt==1)
            a[id-1]=curr;
        else
            b[id-1]=curr;
        vector<int> c(a);
        vector<int> d(b);
        vector<int> discreted;
        sort(c.begin(),c.end());
        sort(d.begin(),d.end());
        for(int i=0;i<k;i++){
            discreted.emplace_back(c[i]);
            discreted.emplace_back(d[i]);
        }
        sort(discreted.begin(),discreted.end());
        discreted.erase(unique(discreted.begin(),discreted.end()),discreted.end());
        DSU dsu(discreted.size());
        for(int i=0;i<k;i++){
            int u=lower_bound(discreted.begin(),discreted.end(),c[i])-discreted.begin();
            int v=lower_bound(discreted.begin(),discreted.end(),d[i])-discreted.begin();
            dsu.unite(u,v);
        }
        for(auto x: c)
            cout<<(dsu.cnt(distance(discreted.begin(),lower_bound(discreted.begin(),discreted.end(),x))))%2<<" ";
        cout<<'\n';
    }
    return 0;
}