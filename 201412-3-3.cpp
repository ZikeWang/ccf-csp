#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef struct Record{
    string type;
    float price;
    long long cnts;
    int line;
    bool operator < (Record const & B) const{
        if(price < B.price)
            return true;
        else
            return false;
    }
}record;

int main()
{
    vector <record> vr;
    record tmp;
    int line = 1;
    while(cin >> tmp.type){
        if(tmp.type == "cancel"){
            int loc;
            cin >> loc;
            vector <record> :: iterator findline;
            for(findline=vr.begin(); findline!=vr.end(); findline++){
                if(findline->line == loc){
                    vr.erase(findline);
                    break;
                }
            }
        }
        else{
            cin >> tmp.price;
            cin >> tmp.cnts;
            tmp.line = line;
            vr.push_back(tmp);
        }
        line++;
    }
    sort(vr.begin(), vr.end());

    vector <record> :: iterator p1;
    vector <record> :: iterator p2;
    vector <record> :: iterator pp1;
    vector <record> :: iterator pp2;

    long long maxc = 0;
    float maxp = 0;

    for(p1=vr.begin(); p1!=vr.end(); p1++){
        p2 = p1+1;
        while(p2 != vr.end() && p2 -> price == p1->price){
            p2++;
        }
        p2--;

        long long bcnt = 0;
        long long scnt = 0;

        for(pp1=p1; pp1!=vr.end(); pp1++){
            if(pp1->type == "buy"){
                bcnt += pp1->cnts;
            }
        }
        for(pp2=vr.begin(); pp2<=p2; pp2++){
            if(pp2->type == "sell"){
                scnt += pp2->cnts;
            }
        }
        long long cnt = (bcnt<scnt)?bcnt:scnt;
        if(cnt > maxc){
            maxc = cnt;
            maxp = p1 -> price;
        }
        else if(cnt == maxc){
            if(p1->price > maxp)
                maxp = p1 -> price;
        }
        p1 = p2;
    }
    printf("%.2f %lld", maxp, maxc);
    return 0;
}

//long long
//line 60 if->while
//line 87 time limit exceed