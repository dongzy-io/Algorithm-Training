#include<bits/stdc++.h>
using namespace std;

class character
{
    private:
        static int rank;
        int currRank;
    protected:
        string name;
        int age;
        int hp;
    public:
        character(string s, int a=21, int h=100):name(s),age(a),hp(h) {
            currRank=rank++;
            cout<<s<<" was born "<<a<<" years ago"<<'\n';
        }
        
        int getRank(){
            return rank;
        }
};

int character::rank=1;

class magic
{
    protected:
        int mana;
    public:
        magic(int m): mana(m){
            cout<<"YOU UNDERESTIMATE MY POWER, MY MASTER"<<'\n';
        }

        int getMAna(){
            return mana;
        }
};

class magicHero: public character, public magic
{
    private:
        string nickname;
        int popularity;
    protected:
        int extraAttack;
    public:
        magicHero(string s1, int a, int h, int m, string s2, int buzz, int EA):character(s1,a,h),magic(m),nickname(s2),popularity(buzz),extraAttack(EA){
            cout<<s1<<" the "<<s2<<" is invincible!"<<'\n';
        }

        string  getNick(){
            return nickname; 
        }

        int getPOp(){
            return popularity;
        }
}; 

class knight: public magicHero
{
    private:
        int hpDiff;
        int powerDiff;
    public:
        knight(string s1, int a, int h, int m, string s2, int buzz, int EA, int hd, int pd):magicHero(s1, a, h, m, s2, buzz, EA),hpDiff(hd),powerDiff(pd){

        }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    knight("Arthur",22,200,0,"gigantic",33,5,20,5);
    
}