#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    unordered_map<string,int> mp;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        mp[s]=0;
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int opt;
        cin>>opt;
        if(opt==1){
            string s;
            int decrement;
            cin>>s>>decrement;
            if(mp.count(s))
                mp[s]+=decrement;
        }else{
            string s;
            cin>>s;
            if(mp.count(s)) 
                cout<<mp[s]<<"\n";
            else 
                cout<<"-1\n";
        }
    }
}