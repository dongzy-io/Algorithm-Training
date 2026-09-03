#include<bits/stdc++.h>
using namespace std;

typedef long long ll; 

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
        int id_1=0,id_2=0;
        vector<int> odd_1;
        vector<int> odd_2;
        vector<int> even_1;
        vector<int> even_2;
        for(int i=0;i<n;i++){
            if(s1[i]=='1'){
                id_1+=i&1;
                if(i&1){
                    odd_1.emplace_back(i);
                }else{
                    even_1.emplace_back(i);
                }
            }
            if(s2[i]=='1'){
                id_2+=i&1;
                if(i&1){
                    odd_2.emplace_back(i);
                }else{
                    even_2.emplace_back(i);
                }
            }
        }
        int cnt_1=odd_1.size()+even_1.size();
        int cnt_2=odd_2.size()+even_2.size();
        if(cnt_1==cnt_2&&id_1==id_2){
            ll ans=0;
            for(int i=0;i<odd_1.size();i++){
                ans+=(ll)abs(odd_1[i]-odd_2[i])/2;
            }
            for(int i=0;i<even_1.size();i++){
                ans+=(ll)abs(even_1[i]-even_2[i])/2;
            }
            cout<<ans;
        }else{
            cout<<-1;
        }
        cout<<'\n';
    }
}