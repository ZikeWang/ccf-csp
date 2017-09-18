#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main(){
    int m, n;
    scanf("%d %d", &m, &n);
    getchar();

    int i;

    vector <string> vc;
    for(i=0; i<m; i++){
        string tmps;
        getline(cin, tmps);
        vc.push_back(tmps);
    }

    map <string, string> ms;
    for(i=0; i<n; i++){
        string s1, s2;
        cin >> s1;
        getline(cin, s2);
        s2.erase(0, 2);
        s2.erase(s2.end()-1);
        ms.insert(pair<string, string>(s1, s2));
    }

    string left = "{{ ";
    string right = " }}";
    string target;

    vector <string> :: iterator viter;
    map <string, string> :: iterator miter;
    for(viter=vc.begin(); viter!=vc.end(); viter++){
        string::size_type loc1, loc2;
        loc1 = (*viter).find(left);
        if(loc1 == string::npos){
            cout << (*viter) << endl;
            continue;
        }
        for(miter=ms.begin(); miter!=ms.end(); miter++){
            string stmp;
            stmp = miter -> first;
            target = left + stmp + right;
            int len = target.size();
            string::size_type loc = (*viter).find(target);
            while(loc != string::npos){
                (*viter).replace(loc, len, miter->second);
                loc = (*viter).find(target);
            }
        }
        loc1 = (*viter).find(left);
        while(loc1 != string::npos){
            loc2 = (*viter).find(right, loc1);
            if(loc2 != string::npos){
                (*viter).erase(loc1, loc2+2-loc1+1);
            }
            loc1 = (*viter).find(left);
        }
        cout << (*viter) << endl;
    }

    return 0;
}

//Line 40 51 不能定义成int或者unsigned int
//90’ 超时