#include<bits/stdc++.h>
using namespace std;

stack<int> s;
int max_square;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    cin>>num;
    vector<int> heights(num);
    for(auto &x: heights){
        cin>>x;
    }
    heights.emplace_back(0);
    for(int i=0;i<num+1;i++){
        while(!s.empty()&&heights[s.top()]>heights[i]){
            int h=heights[s.top()];
            s.pop();
            int w=(s.empty())? i : (i-s.top()-1);
            max_square=max(max_square, h*w);
        }
        s.emplace(i);
    }
    cout<<max_square;
    return 0;
}