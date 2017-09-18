#include <stdio.h>

int array[1001];

int main(){
    int n;
    int i, max, tmp;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", array+i);
    }
    max = 0;
    for(i=1; i<n; i++){
        tmp = array[i] - array[i-1];
        tmp = tmp>0 ? tmp : -tmp;
        if(tmp > max){
            max = tmp;
        }
    }
    printf("%d\n", max);
    return 0;
}
