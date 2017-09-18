#include <stdio.h>

int no[1001];
int cnt[1001];

int main()
{
    int n;
    int i, j, tmp;
    scanf("%d", &n);
    for(i=0; i<1001; i++)
        cnt[i] = 0;
    for(i=0; i<n; i++){
        scanf("%d", &no[i]);
        for(j=0; j<=i; j++)
            if(no[j]==no[i])
                cnt[i]++;
    }
    for(i=0; i<n; i++)
        printf("%d ", cnt[i]);
    return 0;
}
