#include <stdio.h>

int matrix[502][502];

int main()
{
    int n;
    int i, j, cnt, flag;
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("%d ", matrix[1][1]);
    cnt = 1;
    i=1; j=2; flag=1;
    while(cnt < n*n){
        printf("%d ", matrix[i][j]);
        cnt++;
        if(i==n && j==1){
            if(flag == 1){
                i--;
                j++;
                flag = 2;
                continue;
            }
            else if(flag == 3){
                j++;
                flag = 1;
                continue;
            }
        }
        if(i==1 && j == n){
            if(flag == 1){
                i++;
                j--;
                flag = 3;
                continue;
            }
            else if(flag == 2){
                i++;
                flag = 1;
                continue;
            }
        }
        if((i==1&&j!=n || i==n&&j!=1) && flag!=1){
            j++;
            flag = 1;
            continue;
        }
        if((j==1&&i!=n || j==n&&i!=1) && flag!=1){
            i++;
            flag = 1;
            continue;
        }
        if((j==1&&i!=n || i==n&&j!=1) && flag==1){
            i--;
            j++;
            flag = 2;
            continue;
        }
        if((i==1&&j!=n || j==n&&i!=1) && flag==1){
            i++;
            j--;
            flag = 3;
            continue;
        }
        if(i!=1 && j!=1 && i!=n && j!=n){
            if(flag == 2){
                i--;
                j++;
                continue;
            }
            else if(flag == 3){
                i++;
                j--;
                continue;
            }
        }
    }
    return 0;
}

//可以用else if语句对非(1,n)和(n,1)的情况下if语句的判断条件做优化