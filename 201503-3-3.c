#include <stdio.h>
#include <string.h>

#define IsLeap(x) (x%4==0&&x%100!=0)||(x%400==0) ? 1 : 0

int dayofmonth[13][2] = {
    0, 0,
    31, 31,
    28, 29,
    31, 31,
    30, 30,
    31, 31,
    30, 30,
    31, 31,
    31, 31,
    30, 30,
    31, 31,
    30, 30,
    31, 31
};

typedef struct DATE{
    int day;
    int month;
    int year;
}Date;

void nextday(struct DATE *tmp){
    tmp->day++;
    if(tmp->day > dayofmonth[tmp->month][IsLeap(tmp->year)]){
        tmp->day = 1;
        tmp->month++;
        if(tmp->month > 12){
            tmp->month = 1;
            tmp->year++;
        }
    }
}

int days[2052][13][32];

int main(){
    Date tmp;
    int a, b, c, y1, y2;
    int i, cnt, subs, weekday, ans, tc;
    scanf("%d %d %d %d %d", &a, &b, &c, &y1, &y2);
    tmp.year = 1850;
    tmp.month = 1;
    tmp.day = 1;
    cnt = 0;
    tc = c % 7;
    while(tmp.year < 2051){
        days[tmp.year][tmp.month][tmp.day] = cnt++;
        nextday(&tmp);
    }
    for(i=y1; i<=y2; i++){
        subs = days[i][a][1] - days[1850][1][1];
        weekday = ((subs+2)%7+7)%7;
        if(tc >= weekday){
            ans = tc - weekday + 1 + (b - 1)*7;
            if(ans > dayofmonth[a][IsLeap(i)])
                printf("none\n");
            else
                printf("%04d/%02d/%02d\n", i, a, ans);
        }
        else{
            ans = 7 - (weekday - tc) + 1 + (b - 1)*7;
            if(ans > dayofmonth[a][IsLeap(i)])
                printf("none\n");
            else
                printf("%04d/%02d/%02d\n", i, a, ans);
        }
    }
    return 0;
}

//error1 30' Line58和输出没加前置0
//error2 80' tc，weekday的计算是将周日转换为0，而题目输入的周日为7，所以应加上Line 51 