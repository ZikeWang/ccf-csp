#include <stdio.h>

int array[10001];

int main(){
    int n;
    int i, cnt;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", array+i);
    }
    cnt = 0;
    for(i=1; i<=n-2; i++){
        if((array[i-1]>array[i]&&array[i+1]>array[i]) || (array[i-1]<array[i]&&array[i+1]<array[i])){
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
