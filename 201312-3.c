/*error
#include <stdio.h>

int h[1001];

int main(){
	int n;
	int i, j, min, max, tmp;
	while(scanf("%d", &n) != EOF){
		for(i=0; i<n; i++)
			scanf("%d", h+i);
		max = 0;
		for(i=0; i<n; i++){
			min = h[i];
			for(j=i; j<n; j++){
				if(h[j] < min)
					min = h[j];
				tmp = (j-i+1)*min;
				max = tmp>max?tmp:max;
			}
		}
		printf("%d\n", max);
	}
	return 0;
}
*/

#include <stdio.h>

int h[1001];

int main(){
	int n;
	int i, j, min, max, tmp;
	scanf("%d", &n);
	for(i=0; i<n; i++)
		scanf("%d", h+i);
	max = 0;
	for(i=0; i<n; i++){
		min = h[i];
		for(j=i; j<n; j++){
			if(h[j] < min)
				min = h[j];
			tmp = (j-i+1)*min;
			max = tmp>max?tmp:max;
		}
	}
	printf("%d", max);
	return 0;
}

//提交错误依然在于while的使用。该题只有一个输入样例，去掉while部分即可
//line 48加不加换行符均正确