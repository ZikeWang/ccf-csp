/******error**********
#include <stdio.h>

int main(){
	char s[15];
	int num[9];
	int i, sum;
	char ans;
	while(scanf("%s", s) != EOF){
		num[0] = s[0] - '0';
		num[1] = s[2] - '0';
		num[2] = s[3] - '0';
		num[3] = s[4] - '0';
		num[4] = s[6] - '0';
		num[5] = s[7] - '0';
		num[6] = s[8] - '0';
		num[7] = s[9] - '0';
		num[8] = s[10] - '0';

		for(i=0; i<9; i++)
			printf("%d", num[i]);
		printf("\n");

		sum = 0;
		for(i=0; i<9; i++)
			sum += num[i]*(i+1);

		if(sum % 11 < 10){
			if(sum%11 == s[12]-'0')
				printf("Right\n");
			else{
				for(i=0; i<12; i++)
					printf("%c", s[i]);
				printf("%d\n", sum%11);
			}
		}
		else if(sum % 11 == 10){
			if(s[12] == 'X')
				printf("Right\n");
			else{
				for(i=0; i<12; i++)
					printf("%c", s[i]);
				printf("X\n");
			}
		}
	}
	return 0;
}
***************/

#include <stdio.h>

int main(){
	char s[15];
	int num[9];
	int i, sum;
	scanf("%s", s);
	num[0] = s[0] - '0';
	num[1] = s[2] - '0';
	num[2] = s[3] - '0';
	num[3] = s[4] - '0';
	num[4] = s[6] - '0';
	num[5] = s[7] - '0';
	num[6] = s[8] - '0';
	num[7] = s[9] - '0';
	num[8] = s[10] - '0';

	sum = 0;
	for(i=0; i<9; i++)
		sum += num[i]*(i+1);

	if(sum % 11 < 10){
		if(sum%11 == s[12]-'0')
			printf("Right");
		else{
			for(i=0; i<12; i++)
				printf("%c", s[i]);
			printf("%c", sum%11+'0');
		}
	}
	else if(sum % 11 == 10){
		if(s[12] == 'X')
			printf("Right");
		else{
			for(i=0; i<12; i++)
				printf("%c", s[i]);
			printf("X");
		}
	}
	
	return 0;
}

//error 1:Line 78，最后的输出结果应该是字符的形式，之前提交是最后一个如果是数字sum%11则输出了%d
//error 2:Line 9，正确的提交没有while，只有一个测试用例。。（scanf改成gets依然不行，说明这道题只支持一个用例）
//输出后面加不加换行符都能通过