#include<bits/stdc++.h>
using namespace std;

class DSU{
    private:
        vector<int> fa;
        vector<int> size;
    public:
        DSU(int n){
            fa.resize(n);
            size.resize(n);
            for(int i=0;i<n;i++){
                fa[i]=i;
                size[i]=1;
            }
        }
        
        int find(int id){
            if(fa[id]==id)
                return id;
            return fa[id]=find(fa[id]);
        }

        bool unite(int a,int b){
            int root_a=find(a);
            int root_b=find(b);
            if(root_a==root_b)
                return true;
            if(size[root_a]<size[root_b])
                swap(root_a,root_b);
            fa[root_b]=root_a;
            size[root_a]+=size[root_b];
            return false;
        }   
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        bool available=true;
        int n,x,y;
        cin>>n>>x>>y;
        DSU dsu(n);
        vector<int> nums(n);
        for(auto &x: nums){
            cin>>x;
        }
        for(int i=0;i<n;i++){
            if(i+x<n)
                dsu.unite(i,i+x);
            if(i+y<n)   
                dsu.unite(i,i+y);
        }
        for(int i=0;i<n;i++){
            if(!dsu.unite(nums[i]-1,i)){
                available=false;
                break;
            }
        }
        if(available)
            cout<<"YES";
        else
            cout<<"NO";
        cout<<'\n';
    }
    return 0;
}