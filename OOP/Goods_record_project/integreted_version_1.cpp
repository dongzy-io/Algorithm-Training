#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class Goods {
public:
    Goods(int w) :id(nextId++), weight(w){}   // w in grams

    int getId() const{ 
        return id; 
    }

    void buy(){                          // stock in: update all statistics
        stocks[id]=weight;
        totalWeight+=weight;
        ++weight_cnt[weight];
    }

    static bool sell(int id){   
        if(!stocks.count(id)) 
            return false;
        int w=stocks[id];
        stocks.erase(id);
        totalWeight-=w;
        if(--weight_cnt[w]==0) 
            weight_cnt.erase(w);
        return true;
    }

    static void report(){
        cout<<"====== Inventory Report ======\n"
            <<"Total boxes : "<<stocks.size()<<"\n"
            <<"Total weight: "<<totalWeight<<" g ("
            <<fixed<<setprecision(3)<<totalWeight/1000.0<<" kg)\n"
            <<"--- By weight ---\n";
        for(const auto& [w, cnt] :weight_cnt)
            cout<<w<<"g : "<<cnt<<" box(es)\n";
        cout<<"--- Details ---\n";
        for(const auto& [id, w] :stocks)
            cout<<"#"<<id<<"  "<<w<<" g\n";
        cout<<"==============================\n";
    }

private:
    int id;
    int weight;                           // grams
    static int nextId;                    // next ID to assign (shared by all objects)
    static long long totalWeight;         // total stock weight (g)
    static map<int, int> stocks;           // ID -> weight (g)
    static map<int, int> weight_cnt;        // weight (g) -> box count
};
int Goods::nextId=1;
ll Goods::totalWeight=0;
map<int, int> Goods::stocks;
map<int, int> Goods::weight_cnt;

int main(){
    int op;
    cout<<"1.Buy  2.Sell (by ID)  3.Report  0.Exit\n";
    while(cin>>op&&op!=0){
        if(op==1){
            int w;
            cout<<"Weight (g): ";
            cin>>w;
            if(w<=0){ 
                cout<<"Invalid weight\n"; 
                continue; 
            }
            Goods g(w);
            g.buy();
            cout<<"Stocked in, ID #"<<g.getId()<<"\n";
        }else if(op==2){
            int id;
            cout<<"ID: ";
            cin>>id;
            cout<<(Goods::sell(id)? "Sold\n" :"ID not found, sale failed\n");
        }else if(op==3){
            Goods::report();
        }
    }
}