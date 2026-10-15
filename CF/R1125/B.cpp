#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n,i=0,cnt=0;
        string s;
        cin>>n>>s;
        stack<int> mem;
        vector<bool> isPrinted(n);
        for(auto c: s){
            if(c=='1'){
                mem.emplace(i);
            }else if(c=='2'){
                if(mem.empty())
                    isPrinted[i]=true;
                else{
                    isPrinted[mem.top()]=true;
                    mem.pop();
                }
                cnt++;
            }else{
                isPrinted[i]=true;
                cnt++;
            }
            i++;
        }
        cout<<n-cnt<<'\n';
        for(int i=0;i<n;i++){
            if(!isPrinted[i])
                cout<<i+1<<" ";
        }
        cout<<'\n';
    }
    return 0;
}