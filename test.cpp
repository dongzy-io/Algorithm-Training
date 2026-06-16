//used to examine the validity of the greedy version
#include<bits/stdc++.h>
using namespace std;

int op[3]={1,-1,2};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;
    while(T--){
        int a,b;
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0,100);
        a=dis(gen);
        b=dis(gen);
        cout<<a<<" "<<b<<" ";
        //cin>>a>>b;
        int b_temp=b;
        int ans=numeric_limits<int>::max();
        queue<pair<int,int>> path; //pos steps
        path.emplace(a,0);
        int cnt=0;
        while(a!=b){
            if(a>b){
                cnt+=a-b;
                break;
            }else{
                if(a==b/2){
                    cnt++;
                    break;
                }else if(a>b/2){
                    cnt+=min(b-a,a-(b+1)/2+2);
                    break;
                }else{
                    if(b&1){
                        b=(b-1)/2;
                        cnt+=2;
                    }else{
                        b/=2;
                        cnt++;
                    }
                }
            }
        }
        cout<<cnt<<" ";
        // second method
        while(!path.empty()){
            auto p=path.front();
            path.pop();
            int pos=p.first;
            int steps=p.second;
            if(pos==b_temp){
                ans=min(ans,steps);
                continue;
            }
            if(p.second>=ans){
                continue;
            }
            for(int i=0;i<3;i++){
                if(i!=2){
                    path.emplace(pos+op[i],steps+1);
                }else   
                    path.emplace(pos*2,steps+1);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}