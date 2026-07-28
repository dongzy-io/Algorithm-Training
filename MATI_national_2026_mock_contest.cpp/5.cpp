#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int n;
    cin>>n;
    vector<pair<string,int>> sequences(n);
    for(auto &seq:sequences) {
        cin>>seq.first;
        seq.second=0;
    }
    for(auto c:s){
        for(auto &seq:sequences) {
            if(seq.first[seq.second]==c) {
                seq.second++;
            }
        }
    }
    for(auto seq:sequences) {
        if(seq.second==seq.first.size()) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
