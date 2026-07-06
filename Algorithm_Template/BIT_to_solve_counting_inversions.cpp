//to be continued
#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> nums;
vector<int> rankings;

void discrete(vector<int> &origin, vector<int> &discreted)
{
    vector<int> temp(origin);
    sort(temp.begin(),temp.end());
    temp.erase(unique(temp.begin(),temp.end()));
    for(auto x: origin){
        int rank=lower_bound(temp.begin(),temp.end(),x)-temp.begin()+1;//ranked 1,2,3......
        discreted.emplace_back(rank);
    }
}

class BIT
{
    private:
        int n;
        vector<int> tree;
        int lowbit(int x)
        {
            return x&(-x);
        }
    public:
        BIT(int n):
            n(n),tree(n+1,0) {}
        
        void update(int id, int val)
        {
            for(; id<=n; id+=lowbit(id)){
                tree[id]+=val;
            }
        }

        int query(int i)
        {
            int sum=0;
            for(; i>0 ;i-=lowbit(i) ){
                sum+=tree[i];
            }   
            return sum;
        }
};

int countInversions()
{
    int cnt=0;
    BIT bit(n);
    for(int i=0;i<n;i++){
        cnt+=(i-bit.query(rankings[i]));
        bit.update(rankings[i],1);
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    nums.resize(n);
    for(auto &x: nums){
        cin>>x;
    }    
    discrete(nums,rankings);
    cout<<countInversions();
    return 0;
}