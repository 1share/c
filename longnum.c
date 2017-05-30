#include<stdio.h>
#include<string.h>

int isdig(char c) {
	if(c >= '0' && c <= '9' )
		return 1;
	return 0;
}

void change(char *s, char **d) {
	
	char *t = s;
	char *dd = NULL;
	char *b = NULL;
	char *bt = NULL;
	int lm = 0;
	int l = 0;
	
	while(*t) {
		if(!isdig(*t)) {
			t++;	
			continue;
		}

		bt = t;
		l = 0;
		while(isdig(*t)) {
			t++;
			l++;
		}
	
		if (l > lm) {
			lm = l;
			b = bt;
		}	
	}

	memcpy(*d, b, lm);	

	return;
}

int main()
{
	char *s  = "abcd12345ed125ss1239aa";

	char p[1024] = { 0 };
	char *dest = p;

	change(s, &dest);

	printf("output:%s\n", dest);
	printf("output:%s\n", p);



}
