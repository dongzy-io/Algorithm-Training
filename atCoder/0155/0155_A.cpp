#include<bits/stdc++.h>
using namespace std;

vector<int> next_pos;
const string pattern="tanabata";

void get_next()
{
    int len=pattern.length();
    next_pos.assign(len,0);
    for(int i=1,j=0;i<len;i++){
        while(j!=0&&pattern[i]!=pattern[j]){
            j=next_pos[j-1];
        }
        if(pattern[i]==pattern[j]){
            j++;
        }
        next_pos[i]=j;
    }
}

int KMP(const string& s)
{   
    int len=s.length();
    int res=0;
    for(int i=0,j=0;i<len;i++){
        while(j!=0&&s[i]!=pattern[j]){
            j=next_pos[j-1];
        }
        if(s[i]==pattern[j]){
            j++;
        }
        if(j==pattern.length()){
            j=next_pos[j-1];
            res++;
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,max_cnt=0,ans_id=1;
    cin>>n;
    get_next();
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        int cnt=KMP(s);
        if(cnt>max_cnt){
            ans_id=i;
            max_cnt=cnt;
        }
    }
    cout<<ans_id;
    return 0;
}