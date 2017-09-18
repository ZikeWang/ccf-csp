#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s1, s2;
    cin >> s1;

    int opt, n, i;
    cin >> opt;
    cin >> n;

    for(i=0; i<n; i++){
        cin >> s2;
        if(opt == 1){
            if(s2.find(s1) == -1)
                continue;
            else
                cout << s2 << endl;
        }
        else{
            string s3 = s1;
            transform(s3.begin(), s3.end(), s3.begin(), ::tolower);

            string s4 = s2;
            transform(s4.begin(), s4.end(), s4.begin(), ::tolower);

            if(s4.find(s3) == -1)
                continue;
            else
                cout << s2 << endl;
        }
    }
    return 0;
}

//c库<ctype.h> char s[] = "THIS IS A STRING"; s[i] = tolower(s[i]);
//c++库<cctype> string str= "THIS IS A STRING"; str[i] = tolower(str[i]);
//c++库<algorithm> transform(start, end, dst, op); op = ::tolower ::toupper