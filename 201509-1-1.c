#include <stdio.h>

int array[1002];

int main(){
    int n;
    int i, cnt;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", array+i);
    }
    cnt = 1;
    for(i=1; i<n; i++){
        if(array[i] == array[i-1]){
            continue;
        }
        else{
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}
