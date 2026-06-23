//KMP version --2.0
#include<bits/stdc++.h>
using namespace std;

string source;
string pattern;
int cnt;
vector<int> ans;

vector<int> getNext(const string &s)
{
    int len=s.length();
    vector<int> next(len);
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
    int len_m=m.length();
    int len_p=p.length();
    vector<int> next=getNext(p);
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
            j=0;
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