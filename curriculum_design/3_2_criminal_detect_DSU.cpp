//Its extended version is probably wrong 
#include<bits/stdc++.h>
using namespace std;

class DSU{
    private:
        vector<int> fa;
    public:
        DSU(int N){
            fa.resize(N+1);
            for(int i=1;i<=N;i++){
                fa[i]=i;
            }
        }
        int find(int id){
            if(fa[id]==id)
                return id;
            return fa[id]=find(fa[id]);
        }
        void unite(int id_1,int id_2)
        {
            int ancestor_1=find(id_1);
            int ancestor_2=find(id_2);
            if(ancestor_1==ancestor_2)
                return ;
            else
                fa[ancestor_1]=ancestor_2;
        }
};

int main()
{
    //ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;
    cin>>N>>M;
    DSU dsu(N);
    cin.ignore();
    for(int i=0;i<M;i++){
        int a,b;
        char op;
        cin>>op>>a>>b;
        cin.ignore();
        if(op=='D')
            dsu.unite(a,b);
        else    
            if(dsu.find(a)==dsu.find(b))
                cout<<"In the same gang";
            else    
                cout<<"In different gangs";
        cout<<'\n';
    }
    return 0;
}