#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct item{
    int l;
    int r;
    bool isDeleted;
    bool operator>(const item& other)const{
        return r-l>other.r-other.l;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        ll ans=0;
        int n;
        cin>>n;
        vector<int> nums(n);
        vector<bool> isMatched(n+1,true);
        map<int,item,greater<item>> groups; 
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            nums[i]=x;
            groups[x].isDeleted=false;
            if(isMatched[x]){
                isMatched[x]=false;
                groups[x].l=i;
            }else{
                isMatched[x]=true;
                groups[x].r=i;
            }
        }
        for(auto p: groups){
            int num=p.first;
            if(groups[num].isDeleted){
                continue;
            }else if(isMatched[num]){
                isMatched[num]=false;
                ll base=p.second.r-p.second.l;
                ans+=(ll)base*base;
                for(int i=p.second.l+1;i<p.second.r;i++){
                    if(isMatched[nums[i]]){
                        isMatched[nums[i]]=false;
                    }else{
                        groups[nums[i]].isDeleted=true;
                    }
                }
            }else{  
                ans++;
                groups[num].isDeleted=true;
            }
        }
    }
}