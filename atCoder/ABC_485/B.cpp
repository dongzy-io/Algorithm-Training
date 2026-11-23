#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int faucet,drain;
    bool isFound=false, isAvailable;
    vector<string> grid(n);
    for(int i=0;i<n;i++){   
        cin>>grid[i];
        if(!isFound){
            isAvailable=true;
            for(auto c: grid[i]){
                if(c=='o'){
                    isAvailable=false;
                    break;
                }
            }
            if(isAvailable){
                faucet=i+1;
                isFound=true;
            }
        }
    }
    if(isFound){
        cout<<"Faucet "<<faucet;
        return 0;
    }
    for(int j=0;j<m;j++){
        isAvailable=true;
        for(int i=0;i<n;i++){
            if(grid[i][j]=='o'){
                isAvailable=false;
                break;
            }
        }
        if(isAvailable){
            drain=j+1;
            isFound=true;
        }
        if(isFound){
            cout<<"Drain "<<drain;
            return 0;;
        }
    }
    return 0;
}