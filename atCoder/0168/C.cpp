#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class DSU
{
    private:
        vector<int> fa;
        vector<int> sz;
    public:
        DSU(int n): fa(n+1), sz(n+1,1){
            iota(fa.begin(),fa.end(),0);
        }

        int find(int id){
            if(fa[id]==id)
                return id;
            return fa[id]=find(fa[id]);
        }
        
        bool unite(int a, int b){
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
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    ll cnt=0;
    cin>>n>>m;
    DSU dsu(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if(dsu.unite(a,b))
            cnt++;
    }
    if(cnt>m)
        cout<<"No";
    else
        cout<<"Yes";
    cout<<"\n";
    return 0;
}