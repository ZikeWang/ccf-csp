#include <stdio.h>

int num[1001];

int main()
{
    int n;
    int i, j, cnt;
    scanf("%d", &n);
    for(i=0; i<n; i++)
        scanf("%d", num+i);
    cnt = 0;
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(num[j]-num[i] == 1 || num[i]-num[j]==1)
                cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
