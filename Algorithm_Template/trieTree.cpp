#include<bits/stdc++.h>
#define MAX 10002
using namespace std;

vector<string> record;
int id;
int trie[MAX][26];
int cnt[MAX];
 
void insert(string s)
{
    int p=0;
    for(auto c: s){
        int u=c-'a';
        if(!trie[p][u]){
            trie[p][u]=++id;
        }
        p=trie[p][u];
    }
    cnt[p]++;
}

int query(string s)
{
    int p=0;
    for(auto c: s){
        int u=c-'a';
        if(!trie[p][u])
            return 0;
        p=trie[p][u];
    }
    return cnt[p];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    record.resize(n);
    for(auto &s: record){
        cin>>s;
        insert(s);
    }
    for(auto s: record){
        cout<<query(s)<<'\n';
    }
    return 0;
}