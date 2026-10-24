#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    string temp;
    unordered_map<string,int> record;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        record.emplace(s,0);
    }
    for(int i=0;i<m;i++){
        string s;
        cin>>s;
        temp="";
        for(auto &[curr,cnt]: record){
            int diff=0;
            if(curr.length()==s.length()){
                for(int i=0;i<s.length();i++){
                    if(s[i]!=curr[i]){
                        diff++;                       
                    }
                }
            }
            if(!diff){
                cnt++;
                break;
            }
            if(diff==1){
                if(temp.empty())
                    temp=curr;
                else
                    break;
            }
        }
        if(!temp.empty())
            record[temp]++;
    }
}