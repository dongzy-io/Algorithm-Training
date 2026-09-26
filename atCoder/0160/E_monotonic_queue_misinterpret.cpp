#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    ll ans=0;
    vector<int> C(n);
    vector<int> H(n);
    for(int i=0;i<n;i++)
        cin>>C[i]>>H[i];
    vector<vector<int>> color_pos(n+1,vector<int>());
    vector<int> stack_color_cnt(n+1);
    vector<int> st;
    for(int i=0;i<n;i++){
        int color=C[i];
        int height=H[i];
        while(!st.empty()&&H[st.back()]<height){
            stack_color_cnt[C[st.back()]]--;
            st.pop_back();
        }
        int l_id=st.empty()? -1: st.back();
        auto it=lower_bound(color_pos[color].begin(),color_pos[color].end(),l_id+1);
        int dist=distance(it,color_pos[color].end());
        ans+=dist;
        ans+=stack_color_cnt[color];
        stack_color_cnt[color]++;
        color_pos[color].emplace_back(i);
        st.emplace_back(i);
    }    
    cout<<ans;
    return 0;
}