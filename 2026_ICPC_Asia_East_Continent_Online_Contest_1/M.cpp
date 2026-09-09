#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    unordered_set<string> roster;
    unordered_set<string> curr;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        roster.emplace(s);
    }
    while(q--){
        string s;
        cin>>s;
        if(roster.count(s)){
            if(curr.count(s))
                cout<<"REPEAT";
            else{
                curr.emplace(s);
                cout<<"OK";
            }
        }else
            cout<<"WRONG";
        cout<<'\n';
    }
    return 0;
}