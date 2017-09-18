#include <iostream>
#include <string>
#include <map>
using namespace std;

map <char,int> type;
map <char,string> para;
string s,s1,s2;

int main()
{
    bool flag;
    cin>>s;
    for(int i=0; i<s.length()-1; i++)
    {
        if(s[i]!=':' && s[i+1]==':')
            type[s[i]] = 1;
        else if(s[i]!=':')
            type[s[i]] = 2;
    }
    if(s[s.length()-1] != ':')
        type[s[s.length()-1]] = 2;

    int n,p1,p2;
    cin>>n;
    cin.get();//注意避免读入换行符 
    for(int i=0; i<n; i++)
    {
        flag = 0;
        para.clear();
        getline(cin, s);//C++读入带有空格的字符串 
        while((p1=s.find(' ')) != -1)
        {
            s[p1] = 0;
            p2 = s.find(' ');
            if(p2 == -1)
                p2 = s.length();
            s2 = s.substr(p1+1, p2-p1-1);
            if(!flag)
            {
                if(s2[0]!='-' || !type[s2[1]])
                    break;
                if(type[s2[1]] == 2)
                    para[s2[1]] = "*";
                else
                {
                    s1 = s2;
                    flag = 1;
                }
            }

            else
            {
                para[s1[1]] = s2;
                flag = 0;
            }
        }
        cout<<"Case "<<i+1<<":";
        for(map<char,string>::iterator it=para.begin(); it!=para.end(); it++)
        {
            cout<<" -"<<(*it).first;
            if(it->second[0] != '*')
                cout<<' '<<it->second;
        }
        cout<<endl;
    }
}