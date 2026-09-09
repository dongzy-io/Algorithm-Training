#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> a(n);
    int curr=0,id;
    int max_num=0;
    int cnt=0;
    int max_cnt=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>0){
            curr+=a[i];
            if(a[i]==max_num)
                max_cnt++;    
            if(a[i]>max_num){
                id=i+1;
                max_cnt=1;
                max_num=a[i];
            }
        }  
        if(a[i]==-1)
            cnt++;  
    }
    if(n-curr<=max_num){
        cout<<id;
    }else{ 
        for(int i=0;i<n;i++){
            if(a[i]==-1)
                cout<<i+1<<" ";
            if(max_cnt==1&&(max_num-1)*cnt>=(n-curr)&&i+1==id)
                cout<<id<<" ";
        }
    }
    return 0;
}