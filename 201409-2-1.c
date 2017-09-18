#include <stdio.h>
#include <stdlib.h>

int flag[101][101];

int main()
{
    int n, x1, y1, x2, y2;
    int i, j, k, minx, miny, maxx, maxy, cnt;
    scanf("%d", &n);
    minx = 0; miny = 0; maxx = 0; maxy = 0;
    for(i=0; i<n; i++){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if(x1 < minx)
            minx = x1;
        if(y1 < miny)
            miny = y1;
        if(x2 > maxx)
            maxx = x2;
        if(y2 > maxy)
            maxy = y2;
        for(j=x1; j<x2; j++){
            for(k=y1; k<y2; k++){
                if(flag[j][k] == 0)
                    flag[j][k] = 1;
            }
        }
    }
    cnt = 0;
    for(i=minx; i<maxx; i++){
        for(j=miny; j<maxy; j++){
            if(flag[i][j] == 1)
                cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}

//不需要保存点的坐标