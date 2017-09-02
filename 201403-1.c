#include <stdio.h>

int num[501];
int flag[501];

int main(){
	int n;
	int i, j, cnt;
	scanf("%d", &n);
	cnt = 0;
	for(i=0; i<501; i++)
		flag[i] = 0;
	for(i=0; i<n; i++)
		scanf("%d", num+i);
	for(i=0; i<n; i++){
		if(flag[i] == 1)
			continue;
		for(j=i+1; j<n; j++){
			if(num[i]+num[j] == 0){
				cnt++;
				flag[j] = 1;
			}
		}
		flag[i] = 1;
	}
	printf("%d\n", cnt);
	return 0;
}