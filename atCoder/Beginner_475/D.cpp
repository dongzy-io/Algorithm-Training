#include<bits/stdc++.h>
using namespace std;

vector<int> primes;
vector<bool> isPrime(1e7,true);

void sieve()
{
    isPrime[0]=isPrime[1]=false;
    for(int i=0;i<1e7;i++){
        if(isPrime[i])
            primes.emplace_back(i);
        for(auto x: primes){
            if(i*x>1e7)
                break;
            isPrime[i*x]=false;
            if(i%x==0)
                break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    bool has_found=false;
    string s;
    cin>>s;
    int len=s.length();
    int max_l=1,max_r=9;
    for(int i=1;i<len;i++){
        max_l*=10;
        max_r=max_r*10+9;
    }
    for(auto x: primes){
        if(x>=max_l&&x<=max_r){
            bool isAvailable=true;
            string num=to_string(x);
            int char_to_digit[26];
            int digit_to_char[10];
            memset(char_to_digit,-1,sizeof(char_to_digit));
            memset(digit_to_char,-1,sizeof(digit_to_char));
            for(int i=0;i<len;i++){
                int c=s[i]-'a';
                int d=num[i]-'0';
                if(char_to_digit[c]!=-1&&char_to_digit[c]!=d){
                    isAvailable=false;
                    break;
                }
                if(digit_to_char[d]!=-1&&digit_to_char[d]!=c){
                    isAvailable=false;
                    break;
                }
                char_to_digit[c]=d;
                digit_to_char[d]=c;
            }
            if(isAvailable){
                has_found=true;
                cout<<x;
                break;
            }
        }
        if(x>max_r)
            break;
    }
    if(!has_found)
        cout<<-1;  
    return 0;
}