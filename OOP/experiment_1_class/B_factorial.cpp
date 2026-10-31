#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class fac
{
    private:
        int origin_num;
        ll factorial;
    public:
        fac(int x=0): origin_num(x) {
            calc();
        }
        
        void calc(){
            factorial=1;
            for(int i=2;i<=origin_num;i++){
                factorial*=i;
            }
        }        

        int get_origin_num() const{
            return origin_num;
        }

        void set_origin_num(int x){
            origin_num=x;
            calc();
        }

        ll get_fac() const{
            return factorial;
        }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<fac> nums(n);// num  fac
    for(auto &f:nums){
        int x;
        cin>>x;
        f.set_origin_num(x);
    }
    for(const auto &f: nums){
        cout<<f.get_fac()<<" ";
    }
    return 0;
}