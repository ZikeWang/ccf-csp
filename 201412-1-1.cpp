#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n, x;
    map<int, int> num;
    cin >> n;
    while(n--){
        cin >> x;
        map<int, int>::iterator iter;
        for(iter=num.begin(); iter!=num.end(); iter++)
            if(iter->first == x){
                iter->second++;
                break;
            }
        if(iter == num.end())
            num[x] = 1;
        cout << num[x] << " ";
    }
    return 0;
}
