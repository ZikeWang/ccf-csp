#include <stdio.h>

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

int days[2017][13][32];

typedef struct DATE{
    int day;
    int month;
    int year;
}Date;

void nextday(Date *tmp){
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

int main(){
    Date tmp;
    int thisyear, sumdays, i, j, cnt, flag;
    scanf("%d", &thisyear);
    scanf("%d", &sumdays);
    tmp.year = thisyear;
    tmp.month = 1;
    tmp.day = 1;
    cnt = 1;
    while(tmp.year <= thisyear){
        days[tmp.year][tmp.month][tmp.day] = cnt++;
        nextday(&tmp);
    }
    flag = 0;
    for(i=1; i<=12; i++){
        for(j=1; j<=dayofmonth[i][IsLeap(thisyear)]; j++){
            if(days[thisyear][i][j] == sumdays){
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            break;
        }
    }
    printf("%d\n%d", i, j);

    return 0;
}

//不要忘了return 0