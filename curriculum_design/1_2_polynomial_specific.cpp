#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> ans; //exp coef

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    bool isB=false;
    int coef, exp;
    char comon;
    while(true){
        bool isMatched=false;
        cin>>coef>>exp;
        if(!coef){
            if(isB){
                break;
            }
            isB=true;
            continue;
        }   
        cin>>comon;     
        for(auto &p:ans){
            if(p.first==exp){
                p.second+=coef;
                isMatched=true;
                break;
            }
        }
        if(isMatched){
            continue;
        }
        ans.emplace_back(exp,coef);
    }
    int len=ans.size();
    int gap,i,j;
    pair<int,int> pivot;
    //shell sort
	for(gap=len/2;gap>0;gap/=2){
		for(i=gap;i<len;i++){
			pivot=ans[i];
			for(j=i;j>=gap&&ans[j-gap].first>pivot.first;j-=gap)
				ans[j]=ans[j-gap];
			ans[j]=pivot;
		}
	}
    for(auto t:ans){
        if(!t.second)
            continue;
        cout<<" "<<t.second<<" "<<t.first<<",";
    }
    return 0;
}