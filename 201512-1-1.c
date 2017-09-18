#include <stdio.h>
#include <string.h>

int main(){
    char s[100];
    int i, len, ans;
    scanf("%s", s);
    len = strlen(s);
    ans= 0;
    for(i=0; i<len; i++){
        ans += (s[i]-'0');
    }
    printf("%d\n", ans);
    return 0;
}
