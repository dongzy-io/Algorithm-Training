#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        int cnt_1=0,cnt_2=0,id_1=0,id_2=0;
        for(int i=0;i<n;i++){
            if(s1[i]=='1'){
                cnt_1++;
                id_1+=i&1;
            }
            if(s2[i]=='1'){
                cnt_2++;
                id_2+=i&1;
            }
        }
        if(cnt_1==cnt_2&&id_1==id_2){
            cout<<"YES";
        }else{
            cout<<"NO";
        }
        cout<<'\n';
    }
    return 0;
}