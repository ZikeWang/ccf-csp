#include <stdio.h>

struct Num{
	int number;
	int count;
}num[1001];

void swap(int i, int j){
	int tmp_number = num[i].number;
	num[i].number = num[j].number;
	num[j].number = tmp_number;

	int tmp_count = num[i].count;
	num[i].count = num[j].count;
	num[j].count = tmp_count;
}

int main(){
	int n, tmp;
	int i, j, cnt, flag;
	while(scanf("%d", &n) != EOF){
		cnt = 0;
		for(i=0; i<n; i++){
			scanf("%d", &tmp);
			flag = 0;
			for(j=0; j<cnt; j++){
				if(tmp == num[j].number){
					num[j].count++;
					flag = 1;
					break;
				}
			}
			if(!flag){
				num[cnt].number = tmp;
				num[cnt++].count = 1;
			}
		}
		for(i=0; i<cnt; i++)
			for(j=0; j<cnt-1-i; j++){
				if(num[j].count < num[j+1].count)
					swap(j, j+1);
				else if(num[j].count == num[j+1].count){
					if(num[j].number > num[j+1].number)
						swap(j, j+1);
				}
			}

		printf("%d\n", num[0].number);
	}
	return 0;
}