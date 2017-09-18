#include <stdio.h>

int main(){
    int n, m;
    int init[31][31], mark[31][31];
    int i, j, k, cnt;
    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            mark[i][j] = 1;
        }
    }
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            scanf("%d", &init[i][j]);
        }
    }
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            cnt = 1;
            for(k=j+1; k<=m; k++){
                if(init[i][k] == init[i][k-1]){
                    cnt++;
                }
                else
                    break;
            }
            if(cnt >= 3){
                for(k=j; k<=j+cnt-1; k++){
                    mark[i][k] = 0;
                }
            }
            j = j + cnt -1;
        }
    }
    for(j=1; j<=m; j++){
        for(i=1; i<=n; i++){
            cnt = 1;
            for(k=i+1; k<=n; k++){
                if(init[k][j] == init[k-1][j]){
                    cnt++;
                }
                else
                    break;
            }
            if(cnt >= 3){
                for(k=i; k<=i+cnt-1; k++){
                    mark[k][j] = 0;
                }
            }
            i = i + cnt - 1;
        }
    }
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            if(mark[i][j] == 1){
                printf("%d ", init[i][j]);
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
    return 0;
}
