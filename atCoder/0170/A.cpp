#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,score=-1,id=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        int curr=a+b;
        if(curr>score){
            id=i+1;
            score=curr;
        }
    }
    cout<<id;
    return 0;
}