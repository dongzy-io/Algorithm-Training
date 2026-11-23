#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int K,min_num=10;
    cin>>K;
    bool has_9=false;
    for(int i=0;i<K;i++){
        int x;
        cin>>x;
        min_num=min(min_num,x);
        if(x==9)
            has_9=true;
    }
    if(!has_9)
        cout<<-1;
    else
        cout<<min_num;
    return 0;
}