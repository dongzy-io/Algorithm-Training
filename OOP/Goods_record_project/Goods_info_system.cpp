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
        weight_ids[weight].emplace(id);
        totalWeight+=weight;
    }

    static bool sellByID(int id){            // sell by ID
        auto it=stocks.find(id);
        if(it==stocks.end()) 
            return false;
        removeBox(it);
        return true;
    }

    static int sellByWeight(int w){      // sell by weight, returns sold ID (0 = failed)
        auto it=weight_ids.find(w);
        if(it==weight_ids.end()) 
            return 0;
        int soldId=*it->second.begin();  // smallest ID first (FIFO)
        removeBox(stocks.find(soldId));
        return soldId;
    }

    static void report(){
        cout<<"====== Inventory Report ======\n"
            <<"Total boxes : "<<stocks.size()<<"\n"
            <<"Total weight: "<<totalWeight<<" g ("
            <<fixed<<setprecision(3)<<totalWeight/1000.0<<" kg)\n"
            <<"--- By weight ---\n";
        for(const auto& [w, ids] :weight_ids){
            cout<<w<<" g : "<<ids.size()<<" box(es)  IDs:";
            for(int i:ids)
                cout<<" #"<<i;
            cout<<"\n";
        }
        cout<<"--- Details ---\n";
        for(const auto& [id, w] :stocks)
            cout<<"#"<<id<<"  "<<w<<" g\n";
        cout<<"==============================\n";
    }

private:
    static void removeBox(map<int, int>::iterator it){   // shared core of both sell functions
        int boxId=it->first, w=it->second;
        auto& ids=weight_ids[w];
        ids.erase(boxId);
        if(ids.empty()) 
            weight_ids.erase(w);
        stocks.erase(it);
        totalWeight-=w;
    }

    int id;
    int weight;                           // grams
    static int nextId;                    // next ID to assign (shared by all objects)
    static long long totalWeight;         // total stock weight (g)
    static map<int, int> stocks;          // ID -> weight (g)
    static map<int, set<int>> weight_ids; // weight (g) -> set of IDs
};
int Goods::nextId=1;
ll Goods::totalWeight=0;
map<int, int> Goods::stocks;
map<int, set<int>> Goods::weight_ids;

int main(){
    int op;
    cout<<"1.Buy  2.Sell by ID  3.Sell by weight  4.Report  0.Exit\n";
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
            cout<<(Goods::sellByID(id)? "Sold\n" :"ID not found, sale failed\n");
        }else if(op==3){
            int w;
            cout<<"Weight (g): ";
            cin>>w;
            int soldId=Goods::sellByWeight(w);
            if(soldId) 
                cout<<"Sold box #"<<soldId<<"\n";
            else 
                cout<<"No box of that weight, sale failed\n";
        }else if(op==4){
            Goods::report();
        }
    }
}

//以箱为单位，每箱重量不一样，要求记录总重量和货物进出情况
//核心是两个数据结构——一个是【id, weight】,一个是【weight，set】
//因为是服务于两类功能：买进，卖出
//卖出分两种：按编号卖出与按重量卖出
//巧妙的是，两种逻辑共用一种处理手段，先找到数据在stocks中的位置，然后传入函数，更新数据三个数据:
//totalWeight stocks weihgt_ids