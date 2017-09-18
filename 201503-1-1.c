#include <stdio.h>

int array[1002][1002];
int ans[1002][1002];

int main(){
    int n, m;
    int i, j;
    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            scanf("%d", &array[i][j]);
        }
    }
    for(j=m; j>=1; j--){
        for(i=1; i<=n; i++){
            ans[m-j+1][i] = array[i][j];
        }
    }
    for(i=1; i<=m; i++){
        for(j=1; j<=n; j++){
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
