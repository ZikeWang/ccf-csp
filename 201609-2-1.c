#include <stdio.h>

int matrix[21][6];

int main(){
    int n;
    int i, j, p, amount, flag;
    for(i=1; i<=20; i++){
        for(j=1; j<=5; j++){
            matrix[i][j] = 0;
        }
    }
    scanf("%d", &n);
    while(n--){
        scanf("%d", &amount);
        flag = 0;
        for(i=1; i<=20; i++){
            for(j=1; j<=5; j++){
                for(p=j; p<=j+amount-1&&p<=5; p++){
                    if(matrix[i][p] != 0){
                        break;
                    }
                }
                if(p == j+amount){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
                break;
        }
        if(flag == 1){
            for(p=j; p<=j+amount-1; p++){
                printf("%d ", 5*(i-1)+p);
                matrix[i][p] = 1;
            }
            printf("\n");
        }
        else{
            while(amount--){
                for(i=1; i<=20; i++){
                    for(j=1; j<=5; j++){
                        if(matrix[i][j] == 0){
                            matrix[i][j]= 1;
                            printf("%d ", 5*(i-1)+j);
                        }
                    }
                }
                printf("\n");
            }
        }
    }
    return 0;
}
