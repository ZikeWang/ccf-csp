/* partially correct
#include <stdio.h>

struct rectangle{
	int x1;
	int y1;
	int x2;
	int y2;
	int level;
}rec[11];

struct point{
	int x;
	int y;
}p[11];

int ans[11];

int main(){
	int n, m;
	int i, j, cnt, lev, no;
	scanf("%d %d", &n, &m);
	for(i=0; i<n; i++){
		scanf("%d %d %d %d", &rec[i].x1, &rec[i].y1, &rec[i].x2, &rec[i].y2);
		rec[i].level = i+1;
	}
	for(i=0; i<m; i++)
		scanf("%d %d", &p[i].x, &p[i].y);
	cnt = 0;
	for(i=0; i<m; i++){
		lev = -1;
		for(j=0; j<n; j++){
			if(p[i].x>=rec[j].x1&&p[i].x<=rec[j].x2 && p[i].y>=rec[j].y1&&p[i].y<=rec[j].y2){
				lev = rec[j].level;
				no = j;
			}
		}
		ans[cnt++] = lev;
		if(lev != -1){
			for(j=no+1; j<n; j++)
				rec[j].level -= 1;
			rec[no].level = n-1;
		}
	}
	for(i=0; i<m; i++){
		if(ans[i] != -1)
			printf("%d\n", ans[i]);
		else
			printf("IGNORED\n");
	}
	return 0;
}
*/

#include <stdio.h>

struct rectangle{
	int x1;
	int y1;
	int x2;
	int y2;
	int level;
}rec[11];

struct point{
	int x;
	int y;
}p[11];

int ans[11];

void swap(int i, int j){
	int tmp_x1, tmp_x2, tmp_y1, tmp_y2, tmp_level;

	tmp_x1 = rec[i].x1;
	rec[i].x1 = rec[j].x1;
	rec[j].x1 = tmp_x1;

	tmp_x2 = rec[i].x2;
	rec[i].x2 = rec[j].x2;
	rec[j].x2 = tmp_x2;

	tmp_y1 = rec[i].y1;
	rec[i].y1 = rec[j].y1;
	rec[j].y1 = tmp_y1;

	tmp_y2 = rec[i].y2;
	rec[i].y2 = rec[j].y2;
	rec[j].y2 = tmp_y2;

	tmp_level = rec[i].level;
	rec[i].level = rec[j].level;
	rec[j].level = tmp_level;
}

int main(){
	int n, m;
	int i, j, cnt, lev, no;
	scanf("%d %d", &n, &m);
	for(i=0; i<n; i++){
		scanf("%d %d %d %d", &rec[i].x1, &rec[i].y1, &rec[i].x2, &rec[i].y2);
		rec[i].level = i+1;
	}
	for(i=0; i<m; i++)
		scanf("%d %d", &p[i].x, &p[i].y);
	cnt = 0;
	for(i=0; i<m; i++){
		lev = -1;
		for(j=0; j<n; j++){
			if(p[i].x>=rec[j].x1&&p[i].x<=rec[j].x2 && p[i].y>=rec[j].y1&&p[i].y<=rec[j].y2){
				lev = rec[j].level;
				no = j;
			}
		}
		ans[cnt++] = lev;
		if(lev != -1){
			for(j=no; j<n-1; j++)
				swap(j, j+1);
		}
	}
	for(i=0; i<m; i++){
		if(ans[i] != -1)
			printf("%d\n", ans[i]);
		else
			printf("IGNORED\n");
	}
	return 0;
}

//之前提交显示只有部分正确是因为逻辑上考虑不周全，本题的算法是从最下层遍历到最上层
//当获取到最大的层数时即为要点击的层数，遍历时的结构体序号和层号的递增关系是一致的
//那么当选中一层后将将其层号提升到最上层时，相应的应该将其在结构体数组中的序号相应
//地做修改，所以应该采取交换的方式，而不是只简单的修改某个结构体的level域，否则在
//后续的遍历中，当访问到某个最顶层后，如果其后续序号的结构体也符合条件，那么lev就会
//被更小的层号所取代，这样就不满足点击的是最顶层的要求了