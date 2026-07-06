#include<bits/stdc++.h>
using namespace std;

class DSU{
    private:
        vector<int> parent;
    public:
        DSU(int n){
            parent.resize(n);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }
        int find(int id){
            if(parent[id]==id)
                return parent[id];
            return parent[id]=find(parent[id]);
        }
        void unite(int a,int b){
            int ancestor_a=find(a);
            int ancestor_b=find(b);
            if(ancestor_a==ancestor_b){
                return ;
            }
            parent[ancestor_a]=ancestor_b;
        }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    DSU dsu(n);
    return 0;
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        dsu.unite(a,b);
    }
    return 0;
}