// naive KMP
#include<bits/stdc++.h>
using namespace std;

string source,pattern;
vector<int> ans;
int cnt;

vector<int> getNext(const string &s)
{
    int len=s.length();
    vector<int> next(len,0);
    next[0]=0;
    int j=0;
    for(int i=1;i<len;i++){
        while(j>0&&s[i]!=s[j]){
            j=next[j-1];
        }
        if(s[i]==s[j]){
            j++;
        }
        next[i]=j;
    }
    return next;
}

void KMP(const string &m, const string &p)
{
    vector<int> next=getNext(p);
    int len_m=m.length();
    int len_p=p.length();
    for(int i=0,j=0;i<len_m;i++){
        while(j>0&&m[i]!=p[j]){
            j=next[j-1];
        }
        if(m[i]==p[j]){
            j++;
        }
        if(j==len_p){
            cnt++;
            ans.emplace_back(i-len_p+1);
            j=next[j-1];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    getline(cin,source,',');
    cin>>pattern;
    KMP(source,pattern);
    cout<<cnt<<'\n';
    for(auto x: ans){
        cout<<x<<" ";
    }
    return 0;
}