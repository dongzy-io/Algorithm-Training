#include<bits/stdc++.h>
using namespace std;

vector<string> models;
vector<tuple<int,int,int>> edges;// dist index_1 index_2
int ans;

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
                return id;
            return parent[id]=find(parent[id]);
        }
        bool unite(int a, int b){
            int ancestor_a=find(a);
            int ancestor_b=find(b);
            if(ancestor_a==ancestor_b)
                return true;
            return false;
            parent[ancestor_a]=ancestor_b;
        }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    models.resize(n);
    DSU dsu(n);
    for(int i=0;i<n;i++){
        if(i==n-1)
            cin>>models[i];
        else
            getline(cin>>ws,models[i],',');
        models[i]=models[i].substr(0,7);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int cnt=0;
            for(int k=0;k<7;k++){
                if(models[i][k]!=models[j][k])
                    cnt++;
            }
            edges.emplace_back(cnt,i,j);
        }
    }
    sort(edges.begin(),edges.end());
    int cnt=1;
    for(auto e: edges){
        if(!dsu.unite(get<1>(e),get<2>(e))){
            cnt++;
            ans+=get<0>(e);
        }
        if(cnt==n)
            break;
    }
    cout<<ans;
    return 0;
}