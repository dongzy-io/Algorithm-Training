#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n,c;
        cin>>n>>c;
        int sum=0;
        bool isAvailable=true;
        vector<int> a(n);
        vector<int> b(n);
        for(auto &x: a){
            cin>>x;
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
            if(isAvailable&&a[i]>=b[i]){
                sum+=a[i]-b[i];
            }else{
                isAvailable=false;
            }
        }
        if(isAvailable){
            cout<<sum<<'\n';
            continue;
        }
        isAvailable=true;
        sum=0;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(int i=0;i<n;i++){   
            if(a[i]>=b[i]){
                sum+=a[i]-b[i];
            }else{
                isAvailable=false;
                break;
            }
        }
        if(isAvailable)
            cout<<sum+c;
        else
            cout<<-1;
        cout<<'\n';
    }
    return 0;
}