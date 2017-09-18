#include <stdio.h>

struct Number{
    int value;
    int cnt;
}num[1001];

int main(){
    int n, x;
    int i, j, count, tmpv, tmpc;
    scanf("%d", &n);
    for(i=0; i<1001; i++){
        num[i].cnt = 0;
    }
    count = 0;
    for(i=0; i<n; i++){
        scanf("%d", &x);
        for(j=0; j<count; j++){
            if(num[j].value == x){
                num[j].cnt++;
                break;
            }
        }
        if(j == count){
            num[j].value = x;
            num[j].cnt = 1;
            count++;
        }
    }
    for(i=0; i<count; i++){
        for(j=0; j<count-1-i; j++){
            if(num[j].cnt < num[j+1].cnt){
                tmpv = num[j].value;
                num[j].value = num[j+1].value;
                num[j+1].value = tmpv;

                tmpc = num[j].cnt;
                num[j].cnt = num[j+1].cnt;
                num[j+1].cnt = tmpc;
            }
            else if(num[j].cnt == num[j+1].cnt){
                if(num[j].value > num[j+1].value){
                    tmpv = num[j].value;
                    num[j].value = num[j+1].value;
                    num[j+1].value = tmpv;

                    tmpc = num[j].cnt;
                    num[j].cnt = num[j+1].cnt;
                    num[j+1].cnt = tmpc;
                }
            }
        }
    }
    for(i=0; i<count; i++){
        printf("%d %d\n", num[i].value, num[i].cnt);
    }
    return 0;
}
