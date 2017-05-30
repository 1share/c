#include<stdio.h>
#include<string.h>

int change(char *s) {
	
	int max = 0;
	int tmp = 0;
	char *t = s;
	
	while(*t) {
		
		if(*t == '.'){
			max += tmp;
			max *= 256;

			tmp = 0;
			t++;
			continue;
		}	

		tmp *= 10;
		tmp += (*t - '0');


		t++;
	}

	return max + tmp;
}

int main()
{
	int ret;
	char *s  = "123.45.67.89";

	ret = change(s);

	printf("output:%d\n", ret);
}
