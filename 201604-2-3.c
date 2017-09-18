#include <stdio.h>

int big[16][11];
int small[5][5];
int mark[5];
int line[5];
int column[5];

int main(){
    int offset;
    int i, j, cnt, lcnt, ccnt, min, hight, max;
    for(i=1; i<=15; i++){
        for(j=1; j<=10; j++){
            scanf("%d", &big[i][j]);
        }
    }
    for(i=1; i<=4; i++){
        for(j=1; j<=4; j++){
            scanf("%d", &small[i][j]);
        }
    }
    scanf("%d", &offset);
    cnt = 0;
    for(j=1; j<=4; j++){
        for(i=1; i<=4; i++){
            if(small[i][j] == 1){
                mark[cnt++] = offset + j - 1; /*保存大图中有方块落下的列号， cnr为列数*/
                break;
            }
        }
    }
    lcnt = 0;
    for(j=mark[0]; j<=mark[cnt-1]; j++){
        for(i=1; i<=15; i++){
            if(big[i][j] == 1){
                line[lcnt++] = i;
                break;
            }
        }
        if(i == 16){
            line[lcnt++] = 100;
        }
    }
    ccnt = 0;
    for(j=mark[0]+1-offset; j<=mark[cnt-1]+1-offset; j++){
        for(i=4; i>=1; i--){
            if(small[i][j] == 1){
                column[ccnt++] = i;
                break;
            }
        }
    }
    max = 0;
    for(i=0; i<ccnt; i++){
        if(column[i] > max){
            max = column[i];
        }
    }
    for(i=0; i<ccnt; i++){
        column[i] -= max;
    }
    min = 20;
    for(i=0; i<cnt; i++){
        if(line[i] - column[i] < min){
            min = line[i] - column[i];
        }
    }
    if(min < 15)
        hight = min - 1;
    else
        hight = 15;
    for(i=1; i<=4; i++){
        for(j=1; j<=4; j++){
            if(small[i][j] == 1){
                big[i+hight-max][offset+j-1] = 1;
            }
        }
    }
    for(i=1; i<=15; i++){
        for(j=1; j<=10; j++){
            printf("%d ", big[i][j]);
        }
        printf("\n");
    }
    return 0;
}
